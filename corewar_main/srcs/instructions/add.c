/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** add.c
*/

#include "cmd.h"

void e_add(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int first_value = get_arg_value(global, REG, address + 2, prog);
    int second_value = get_arg_value(global, REG, address + 3, prog);
    int reg = global->memory[select_address(address + 4)];
    int result = first_value + second_value;

    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
    add_pc(&prog->pc, 5);
}
