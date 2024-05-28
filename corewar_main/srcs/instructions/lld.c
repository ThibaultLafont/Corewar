/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** lld.c
*/

#include "cmd.h"

void e_lld(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1), REG,
    NO};
    int first_arg = get_arg_value(global, args[0], address + 2, prog);
    int first_size = get_type_size(args[0]);
    int reg = global->memory[select_address(address + 2 + first_size)];

    prog->registers[reg - 1] = first_arg;
    prog->carry = (first_arg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
