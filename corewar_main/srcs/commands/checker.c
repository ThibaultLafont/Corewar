/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** checker.c
*/

#include <stdio.h>
#include "cmd.h"
/**
 * Checks if the given argument matches any of the valid argument types.
 *
 * @param arg - The argument to check.
 * @param types - The valid argument types.
 * @return 1 if the argument matches any of the valid types, 0 otherwise.
 */
static int arg_matches_types(int arg, valid_args_t types)
{
    return types.first_arg == arg ||
    types.second_arg == arg ||
    types.third_arg == arg;
}

/**
 * Verifies if the given command has valid arguments.
 *
 * @param cmd - The command to verify.
 * @param first_arg - The first argument of the command.
 * @param second_arg - The second argument of the command.
 * @param third_arg - The third argument of the command.
 * @return 1 if the command has valid arguments, 0 otherwise.
 */
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

/**
 * Checks if the opcode of the command at the given address is valid.
 *
 * @param global - The global structure.
 * @param address - The address of the command.
 * @return 1 if the opcode is valid, 0 otherwise.
 */
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

/**
 * Gets the size of the argument at the given address and position.
 *
 * @param global - The global structure.
 * @param address - The address of the command.
 * @param cmd - The command.
 * @param arg - The argument position.
 * @return The size of the argument.
 */
int get_parcour_value(corewar_t *global, int address, int cmd, int arg)
{
    if (!CMDS[cmd].has_op_code ||
    get_argument_type(global, address, arg) == NO) {
        return (get_type_size(CMDS[cmd].args_types[arg - 1].first_arg));
    }
    return (get_type_size(get_argument_type(global, address, arg)));
}

/**
 * Checks if the registers used in the command at the given address are valid.
 *
 * @param global - The global structure.
 * @param address - The address of the command.
 * @return 1 if the registers are valid, 0 otherwise.
 */
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

/**
 * Checks if the command at the given address is valid.
 *
 * @param global - The global structure.
 * @param address - The address of the command.
 * @return 1 if the command is valid, 0 otherwise.
 */
int check_cmd(corewar_t *global, int address)
{
    int cmd = global->memory[select_address(address)];

    if (cmd < 1 || cmd > 16)
        return 0;
    if (!check_op_code(global, address) || !check_registers(global, address))
        return 0;
    return 1;
}
