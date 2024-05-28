/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** verify_size.c
*/

#include "corewar.h"

int verif_size(corewar_t *global)
{
    int size = 0;

    for (int i = 0; global->progs[i] != NULL; i++)
        size += global->progs[i]->size;
    if (size > MEM_SIZE)
        return (print_error("Size Error: too long programs.\n"));
    return 0;
}
