/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** sort_progs.c
*/

#include "corewar.h"

int bubble_sort_progs(corewar_t *global)
{
    int sorted = 1;
    prog_t *swap = NULL;

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i + 1] == NULL)
            break;
        if (global->progs[i]->id > global->progs[i + 1]->id) {
            swap = global->progs[i];
            global->progs[i] = global->progs[i + 1];
            global->progs[i + 1] = swap;
            sorted = 0;
        }
    }
    return sorted;
}

void sort_progs(corewar_t *global)
{
    while (!bubble_sort_progs(global));
}
