/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** cycle_loop.c
*/

#include <stdio.h>
#include "corewar.h"
#include "my.h"

/**
 * Checks if the cycle should continue or not.
 * The cycle should continue if the number of cycles
 * to dump is greater than 0 and the current cycle
 * is less than the number of cycles to dump.
 * The cycle should also continue if there is at least
 * one program in the global variable.
 *
 * @param global The global variable containing the state of the program.
 * @return 0 if the cycle should not continue, FAILURE otherwise.
 */
int continue_cycle(corewar_t *global)
{
    if (global->nbr_cycle_dump > 0 &&
        global->cycle >= global->nbr_cycle_dump)
        return 0;
    if (get_all_progs_sizes(global) < 1)
        return 0;
    return FAILURE;
}

/**
 * @brief Executes the main loop cycle of the corewar program.
 * 
 * This function executes the main loop cycle of the corewar program. It checks if the list of programs is not empty,
 * and then continues the cycle until the condition specified by the continue_cycle() function is met. 
 * In each iteration of the cycle, the programs are sorted, the current instruction is executed, and dead programs are deleted.
 * The cycle count is incremented after each iteration. Finally, the winner of the corewar program is displayed.
 * 
 * @param global A pointer to the corewar_t structure representing the global state of the corewar program.
 * @return Returns 0 if the main loop cycle is executed successfully, or FAILURE if the list of programs is empty.
 */
int main_loop_cycle(corewar_t *global)
{
    if (global->progs == NULL)
        return FAILURE;
    while (continue_cycle(global)) {
        sort_progs(global);
        exec_instruction(global);
        delete_dead_progs(global);
        global->cycle++;
    }
    show_winner(global);
    return 0;
}
