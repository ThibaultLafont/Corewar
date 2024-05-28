/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** live.c
*/

#include <stdio.h>

#include <stdlib.h>
#include "my.h"
#include "cmd.h"
#include "corewar.h"

void print_alive(prog_t *prog)
{
    my_putstr("The player ");
    my_putnbr(prog->id);
    my_putchar('(');
    my_putstr(prog->name);
    my_putstr(")is alive.\n");
}

/**
 * @brief Displays the "alive" message for a program and updates the global state.
 *
 * This function prints the "alive" message for the given program and updates the global state
 * by freeing the previously stored last alive program name and assigning the new program name
 * and ID to the global variables.
 *
 * @param prog A pointer to the program structure.
 * @param global A pointer to the global state structure.
 */
void show_alive(prog_t *prog, corewar_t *global)
{
    print_alive(prog);
    if (global->last_alive != NULL)
        free(global->last_alive);
    global->last_alive = my_strdup(prog->name);
    global->last_live_id = prog->id;
}

/**
 * Executes the live instruction.
 * This instruction checks if the given argument matches the ID of any program in the global program list.
 * If a match is found, it updates the live_call_cycle of the program and increments the live_calls counter.
 * If the argument matches the ID of the current program, it also calls the show_alive function.
 * Additionally, if the live_calls counter reaches the NBR_LIVE threshold, it resets the counter and decreases the cycles_to_die value.
 *
 * @param global The global state of the Corewar program.
 * @param prog The program executing the live instruction.
 */
void e_live(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    long arg = get_actual_4_bytes(global, address + 1);

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->id == arg)
            global->progs[i]->live_call_cyle = global->cycle;
    }
    add_pc(&prog->pc, 5);
    if (arg == prog->id)
        show_alive(prog, global);
    global->live_calls += 1;
    if (global->live_calls >= NBR_LIVE) {
        global->live_calls = 0;
        global->cycles_to_die -= CYCLE_DELTA;
    }
}
