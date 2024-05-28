/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** bytes_manip.c
*/

#include "cmd.h"
#include "corewar.h"

/**
 * Retrieves the argument type for a given command and argument index.
 *
 * @param global The global state of the corewar.
 * @param cmd_address The address of the command in memory.
 * @param arg The index of the argument.
 * @return The argument type.
 */
arg_type_t get_argument_type(corewar_t *global, int cmd_address, int arg)
{
    int cmd = global->memory[select_address(cmd_address)] - 1;
    int op_code = global->memory[select_address(cmd_address + 1)];
    int result = (op_code >> 6) & 3;
    int second_arg = (op_code >> 4) & 3;
    int third_arg = (op_code >> 2) & 3;

    if (arg == 2)
        result = second_arg;
    if (arg == 3)
        result = third_arg;
    for (int i = 0; i < 3; i++) {
        if (CMDS[cmd].args_types[i].first_arg == DIR4 ||
        CMDS[cmd].args_types[i].second_arg == DIR4 ||
        CMDS[cmd].args_types[i].third_arg == DIR4)
            result = (result == DIR2) ? DIR4 : result;
    }
    if (!CMDS[cmd].has_op_code || result == NO)
        return CMDS[cmd].args_types[arg - 1].first_arg;
    return result;
}

/**
 * Retrieves the actual 4-byte value from the memory at the given address.
 *
 * @param global The global state of the corewar program.
 * @param address The memory address to retrieve the value from.
 * @return The actual 4-byte value from the memory.
 */
long get_actual_4_bytes(corewar_t *global, int address)
{
    int value = global->memory[select_address(address)];

    for (int i = 1; i < 4; i++)
        value = (value << 8) + global->memory[select_address(address + i)];
    return value;
}

/**
 * Retrieves the value of a 2-byte memory address in the global memory array.
 *
 * @param global The corewar_t structure representing the global state of the program.
 * @param address The memory address to retrieve the value from.
 * @return The value stored at the specified memory address.
 */
int get_actual_2_bytes(corewar_t *global, int address)
{
    int value = global->memory[select_address(address)] & MAX_BYTES;

    value = ((value << 8) & HIGH_BYTE) +
    (global->memory[select_address(address + 1)] & MAX_BYTES);
    return value;
}

/**
 * Retrieves the value of an argument based on its type and address.
 *
 * @param global The global state of the corewar program.
 * @param type The type of the argument (REG, IND, DIR2, or default).
 * @param address The address of the argument in memory.
 * @param prog The program structure containing registers and program counter.
 * @return The value of the argument.
 */
long get_arg_value(corewar_t *global, arg_type_t type,
    int address, prog_t *prog)
{
    switch (type) {
        case REG:
            return prog->registers[global->memory[select_address(address)] -
            1];
        case IND:
            return get_actual_4_bytes(global,
            select_address(get_actual_2_bytes(global, address) +
            prog->address + prog->pc));
        case DIR2:
            return get_actual_2_bytes(global, address);
        default:
            return get_actual_4_bytes(global, address);
    }
}

/**
 * Retrieves the value of an argument based on its type and address.
 *
 * @param global The global state of the corewar program.
 * @param type The type of the argument (REG, IND, DIR2).
 * @param address The address of the argument in memory.
 * @param prog The program that contains the argument.
 * @return The value of the argument.
 */
long get_arg_value_mod(corewar_t *global, arg_type_t type,
    int address, prog_t *prog)
{
    switch (type) {
        case REG:
            return prog->registers[global->memory[select_address(address)] -
            1];
        case IND:
            return get_actual_4_bytes(global,
            select_address((get_actual_2_bytes(global, address) % IDX_MOD) +
            prog->address + prog->pc));
        case DIR2:
            return get_actual_2_bytes(global, address);
        default:
            return get_actual_4_bytes(global, address);
    }
}
