/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** destroy_n_add.c
*/

#include <stdlib.h>
#include "corewar.h"

int get_all_progs_sizes(corewar_t *global)
{
    int size = 0;

    if (global->progs == NULL)
        return 0;
    for (; global->progs[size] != NULL; size++);
    return size;
}

void add_prog(corewar_t *global, prog_t *prog)
{
    int size = get_all_progs_sizes(global);
    prog_t **new_prog = malloc(sizeof(prog_t *) * (size + 2));

    new_prog[size + 1] = NULL;
    new_prog[size] = prog;
    if (global->progs == NULL) {
        global->progs = new_prog;
        return;
    }
    for (int i = 0; i < size; i++)
        new_prog[i] = global->progs[i];
    free(global->progs);
    global->progs = new_prog;
}

void free_prog(prog_t *prog)
{
    free(prog->content);
    free(prog->registers);
    free(prog);
}

void destroy_prog(corewar_t *global, prog_t *prog)
{
    int size = get_all_progs_sizes(global);
    prog_t **new = malloc(sizeof(prog_t *) * (size + 1));
    int index = 0;

    new[size] = NULL;
    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i] != prog) {
            new[index] = global->progs[i];
            index++;
        }
    }
    free_prog(prog);
    new[index] = NULL;
    free(global->progs);
    global->progs = new;
}

int get_valid_id(corewar_t *global)
{
    int id = 0;
    int i = 0;

    if (global->progs == NULL)
        return 0;
    while (global->progs[i] != NULL) {
        if (global->progs[i]->id == id) {
            id++;
            i = 0;
        } else {
            i++;
        }
    }
    return id;
}
