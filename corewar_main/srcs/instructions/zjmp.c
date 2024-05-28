/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** zjmp.c
*/

#include "cmd.h"

void e_zjump(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int add = get_actual_2_bytes(global, address + 1);

    if (prog->carry)
        add_pc(&prog->pc, add);
    else
        add_pc(&prog->pc, 3);
}
