/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** main.c
*/

#include <stdlib.h>
#include "corewar.h"

void free_all(corewar_t *global)
{
    free(global->memory);
    free(global->progs);
    free(global);
}

corewar_t *init_global(corewar_t *global, int argc, char **argv)
{
    global = malloc(sizeof(corewar_t));
    if (global == NULL)
        return (NULL);
    global->argc = argc;
    global->argv = argv;
    global->nbr_cycle_dump = -1;
    global->cycle = 0;
    global->cycles_to_die = CYCLE_TO_DIE;
    global->last_alive = NULL;
    global->last_live_id = -1;
    global->live_calls = 0;
    global->progs = NULL;
    global->memory = malloc(sizeof(int) * MEM_SIZE);
    for (int i = 0; i < MEM_SIZE; i++)
        global->memory[i] = 0;
    return (global);
}

int core_program(corewar_t *global)
{
    if (place_progs(global) == FAILURE)
        return FAILURE;
    if (main_loop_cycle(global) == FAILURE)
        return FAILURE;
    if (destroy_every_progs(global) == FAILURE)
        return FAILURE;
    return 0;
}

int main(int argc, char **argv)
{
    corewar_t *global = NULL;
    int status = 0;

    global = init_global(global, argc, argv);
    if (global == NULL)
        return FAILURE;
    status = manage_all_args(global);
    if (status == 1)
        return 0;
    if (status == FAILURE)
        return FAILURE;
    if (core_program(global) == FAILURE)
        return FAILURE;
    free_all(global);
    return 0;
}
