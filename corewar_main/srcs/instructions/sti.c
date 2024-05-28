/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** sti.c
*/

#include "cmd.h"

void e_sti(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {REG, get_argument_type(global, address, 2),
    get_argument_type(global, address, 3)};
    int reg = get_arg_value_mod(global, REG, address + 2, prog);
    int second_arg = get_arg_value_mod(global, args[1], address + 3, prog);
    int second_size = get_type_size(args[1]);
    int third_arg =
    get_arg_value_mod(global, args[2], address + 3 + second_size, prog);
    int add = second_arg + third_arg;

    write_4bytes(global, address + add % IDX_MOD, reg, prog->id);
    prog->carry = (reg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
