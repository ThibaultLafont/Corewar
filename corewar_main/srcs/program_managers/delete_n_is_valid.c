/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** delete_n_is_valid.c
*/

#include "my.h"
#include "corewar.h"

int is_prog_id_valid(corewar_t *global, long id)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] == NULL; i++) {
        if (global->progs[i]->id == id)
            return 0;
    }
    if (id < 0)
        return 0;
    return 1;
}

int is_prog_address_valid(corewar_t *global, int address)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == address)
            return 0;
    }
    return 1;
}

void delete_dead_progs(corewar_t *global)
{
    int redo = 0;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (ABS(global->cycle - global->progs[i]->live_call_cyle) >
        global->cycles_to_die) {
            destroy_prog(global, global->progs[i]);
            redo = 1;
            break;
        }
    }
    if (redo)
        delete_dead_progs(global);
}

int destroy_every_progs(corewar_t *global)
{
    if (global->progs == NULL)
        return 0;
    for (int i = 0; global->progs[i] != NULL; i++)
        destroy_prog(global, global->progs[i]);
    return 0;
}
