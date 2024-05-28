/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** place_n_check_progs.c
*/

#include <stdio.h>
#include "corewar.h"

void place_prog_at(corewar_t *global, prog_t *prog, int address)
{
    for (int i = 0; i < prog->size; i++)
        global->memory[select_address(i + address)] = prog->content[i];
    prog->address = address;
}

int test_place(prog_t *progp, prog_t *prog, int address)
{
    for (int j = progp->address; j < progp->address + progp->size; j++) {
        if (j >= address && j <= address + prog->size)
            return 0;
    }
    return 1;
}

int can_place_prog(corewar_t *global, prog_t *prog, int address)
{
    if (global->progs == NULL)
        return 1;
    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address != -1 &&
        !test_place(global->progs[i], prog, address)) {
            return 0;
        }
    }
    return 1;
}

int place_prog_if_address_negative(corewar_t *global, prog_t *prog,
    int address, int space)
{
    for (; !can_place_prog(global, prog, address); address++);
        address += (address == 0) ? 0 : space;
    place_prog_at(global, prog, address);
    address += prog->size;
    return address;
}

void place_normal(corewar_t *global, int space)
{
    int address = 0;

    for (int i = 0; global->progs[i] != NULL; i++) {
        if (global->progs[i]->address == -1) {
            address = place_prog_if_address_negative(global,
            global->progs[i], address, space);
        }
    }
}
