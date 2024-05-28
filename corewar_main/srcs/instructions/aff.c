/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** aff.c
*/

#include "my.h"
#include "cmd.h"

void e_aff(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int reg = get_arg_value(global, REG, address + 2, prog);
    char character = reg % 256;

    my_putchar(character);
    prog->carry = (character == 0) ? 1 : 0;
    add_pc(&prog->pc, 3);
}
