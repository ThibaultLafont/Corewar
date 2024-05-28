/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** zjmp.c
*/

#include "cmd.h"

/**
 * @brief Executes the zjmp instruction.
 *
 * This function is responsible for executing the zjmp instruction in the corewar game.
 * It checks if the carry flag of the program is set, and if so, it adds the value of the next 2 bytes
 * to the program counter (pc). If the carry flag is not set, it adds 3 to the program counter.
 *
 * @param global A pointer to the global state of the corewar game.
 * @param prog A pointer to the program executing the instruction.
 */
void e_zjump(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int add = get_actual_2_bytes(global, address + 1);

    if (prog->carry)
        add_pc(&prog->pc, add);
    else
        add_pc(&prog->pc, 3);
}
