/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** lfork.c
*/

#include "cmd.h"

void e_lfork(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int arg = get_arg_value(global, DIR2, address + 1, prog);
    prog_t *new = create_prog_copy(prog, global);

    new->address = address + prog->size + arg;
    new->pc = prog->pc + arg;
    place_prog_at(global, new, new->address);
    add_prog(global, new);
    add_pc(&prog->pc, 3);
}
