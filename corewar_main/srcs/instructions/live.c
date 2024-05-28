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

void show_alive(prog_t *prog, corewar_t *global)
{
    if (global->last_alive != NULL)
        free(global->last_alive);
    global->last_alive = my_strdup(prog->name);
    global->last_live_id = prog->id;
}

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
