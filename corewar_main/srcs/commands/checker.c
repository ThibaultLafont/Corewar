/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** checker.c
*/

#include <stdio.h>
#include "cmd.h"

static int arg_matches_types(int arg, valid_args_t types)
{
    return types.first_arg == arg ||
    types.second_arg == arg ||
    types.third_arg == arg;
}

int verify_args(int cmd, int first_arg, int second_arg, int third_arg)
{
    int args[3] = {first_arg, second_arg, third_arg};

    for (int i = 0; i < CMDS[cmd].args_nbr; i++) {
        if (!arg_matches_types(args[i], CMDS[cmd].args_types[i])) {
            return 0;
        }
    }
    return 1;
}

int check_op_code(corewar_t *global, int address)
{
    int cmd = global->memory[select_address(address)] - 1;
    int first_arg = 0;
    int second_arg = 0;
    int third_arg = 0;

    if (!CMDS[cmd].has_op_code)
        return 1;
    first_arg = get_argument_type(global, address, 1);
    second_arg = get_argument_type(global, address, 2);
    third_arg = get_argument_type(global, address, 3);
    if (!verify_args(cmd, first_arg, second_arg, third_arg))
        return 0;
    return 1;
}

int get_parcour_value(corewar_t *global, int address, int cmd, int arg)
{
    if (!CMDS[cmd].has_op_code ||
    get_argument_type(global, address, arg) == NO) {
        return (get_type_size(CMDS[cmd].args_types[arg - 1].first_arg));
    }
    return (get_type_size(get_argument_type(global, address, arg)));
}

int check_registers(corewar_t *global, int address)
{
    int cmd = global->memory[select_address(address)] - 1;
    int parcour = address + 2;

    if (!CMDS[cmd].has_op_code)
        parcour -= 1;
    for (int i = 0; i < CMDS[cmd].args_nbr; i++) {
        if (get_parcour_value(global, address, cmd, i + 1) == T_REG &&
        (global->memory[select_address(parcour)] > 16 ||
        global->memory[select_address(parcour)] < 1))
                return 0;
        parcour += get_parcour_value(global, address, cmd, i + 1);
    }
    return 1;
}

int check_cmd(corewar_t *global, int address)
{
    int cmd = global->memory[select_address(address)];

    if (cmd < 1 || cmd > 16)
        return 0;
    if (!check_op_code(global, address) || !check_registers(global, address))
        return 0;
    return 1;
}
