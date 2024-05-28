/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** place_n_check_progs_bis.c
*/

#include "cmd.h"
#include "my.h"
#include "corewar.h"
#include <stdio.h>

int place_progs(corewar_t *global)
{
    int empty = MEM_SIZE;
    int space;

    if (verif_size(global) == FAILURE)
        return FAILURE;
    if (global->progs == NULL)
        return FAILURE;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address != -1 && !can_place_prog(global,
        global->progs[i], global->progs[i]->address))
            return (print_error("Place Error: Bad champions placement.\n"));
        if (global->progs[i]->address != -1) {
            empty -= global->progs[i]->size;
            place_prog_at(global, global->progs[i],
            global->progs[i]->address);
        }
    }
    space = empty / get_all_progs_sizes(global);
    place_normal(global, space);
    return 0;
}
