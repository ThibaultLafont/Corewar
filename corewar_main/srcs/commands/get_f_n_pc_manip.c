/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** get_f_n_pc_manip.c
*/

#include "cmd.h"
#include "corewar.h"

/**
 * Calculates the new address based on the current program's address and program counter (pc).
 * @param prog The program structure.
 * @return The new address.
 */
int get_new_adress(prog_t *prog)
{
    return select_address(prog->address + prog->pc);
}

/**
 * Retrieves the duration of a command based on its ID.
 * @param id The ID of the command.
 * @return The duration of the command, or -1 if the ID is invalid.
 */
int get_command_duration(int id)
{
    if (id < 1 || id > 16)
        return -1;
    return CMDS[id - 1].duration;
}

/**
 * Adds a value to the program counter (pc).
 * @param pc A pointer to the program counter.
 * @param nb The value to add to the program counter.
 */
void add_pc(int *pc, int nb)
{
    *pc = (*pc + nb) % ONE_MORE_THAN_MAX_USHORT;
}

/**
 * Selects a valid address within the memory size.
 * @param address The address to select.
 * @return The selected address.
 */
int select_address(int address)
{
    address %= MEM_SIZE;
    if (address < 0)
        address += MEM_SIZE;
    return address;
}

/**
 * Retrieves the size of a given argument type.
 * @param type The argument type.
 * @return The size of the argument type.
 */
int get_type_size(arg_type_t type)
{
    switch (type) {
    case REG:
        return (T_REG);
        break;
    case IND:
        return (T_IND);
        break;
    case DIR2:
        return (T_DIR2);
        break;
    case DIR4:
        return (T_DIR4);
        break;
    }
    return 0;
}
