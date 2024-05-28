/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** ld.c
*/

#include "cmd.h"
#include "corewar.h"

void e_ld(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t first_arg_type = get_argument_type(global, address, 1);
    arg_type_t args[3] = {first_arg_type, REG, NO};
    size__t first_arg_size = get_type_size(first_arg_type);
    int first_arg = get_arg_value_mod(
        global, first_arg_type, address + 2, prog);
    int reg_address = select_address(address + 2 + first_arg_size);
    int reg = global->memory[reg_address];

    prog->registers[reg - 1] = first_arg;
    prog->carry = (first_arg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
