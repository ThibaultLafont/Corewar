/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** st.c
*/

#include "cmd.h"

void e_st(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {REG, get_argument_type(global, address, 2), NO};
    int reg = get_arg_value_mod(global, REG, address + 2, prog);
    int second_arg = get_arg_value_mod(global, args[1], address + 3, prog);

    if (args[1] == REG) {
        second_arg = global->memory[select_address(address + 3)];
        prog->registers[second_arg - 1] = reg;
    } else
        write_4bytes(global,
        select_address(address + second_arg % IDX_MOD), reg, prog->id);
    prog->carry = (reg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
