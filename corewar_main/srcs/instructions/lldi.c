/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** lldi.c
*/

#include "cmd.h"

void e_lldi(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int first_arg = get_arg_value(global, args[0], address + 2, prog);
    int first_size = get_type_size(args[0]);
    int second_arg =
    get_arg_value(global, args[1], address + 2 + first_size, prog);
    int second_size = get_type_size(args[1]);
    int value = get_actual_4_bytes(global, address + first_arg + second_arg);
    int reg =
    global->memory[select_address(address + 2 + first_size + second_size)];

    prog->registers[reg - 1] = value;
    prog->carry = (value == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
