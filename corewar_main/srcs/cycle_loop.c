/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** cycle_loop.c
*/

#include <stdio.h>
#include "corewar.h"
#include "my.h"

int continue_cycle(corewar_t *global)
{
    if (global->nbr_cycle_dump > 0 &&
        global->cycle >= global->nbr_cycle_dump)
        return 0;
    if (get_all_progs_sizes(global) < 1)
        return 0;
    return FAILURE;
}

int main_loop_cycle(corewar_t *global)
{
    if (global->progs == NULL)
        return FAILURE;
    while (continue_cycle(global)) {
        sort_progs(global);
        exec_instruction(global);
        delete_dead_progs(global);
        global->cycle++;
        display_arena(global->memory, global);
        usleep(100);
    }
    show_winner(global);
    return 0;
}
