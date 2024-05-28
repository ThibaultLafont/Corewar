/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** xor.c
*/

#include "cmd.h"

int get_first_arg(corewar_t *global, prog_t *prog,
    arg_type_t *args, int address)
{
    int first_arg = get_arg_value_mod(global, args[0], address + 2, prog);

    return first_arg;
}

int get_reg(corewar_t *global, int address, int first_size, int second_size)
{
    int reg =
    global->memory[select_address(address + 2 + first_size + second_size)];

    return reg;
}

void update_prog(prog_t *prog, int reg, int result, arg_type_t *args)
{
    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}

void e_xor(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int first_arg = get_first_arg(global, prog, args, address);
    int first_size = get_type_size(args[0]);
    int second_arg =
    get_arg_value_mod(global, args[1], address + 2 + first_size, prog);
    int second_size = get_type_size(args[1]);
    int reg = get_reg(global, address, first_size, second_size);
    int result = first_arg ^ second_arg;

    update_prog(prog, reg, result, args);
}
