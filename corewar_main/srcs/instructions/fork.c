/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** fork.c
*/

#include <stdlib.h>
#include "my.h"
#include "cmd.h"

void copy_registers(int *dest, int *src, int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

void copy_content(char *dest, int *src, int size, int address)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[select_address(address + i)];
}

prog_t *create_prog_copy(prog_t *prog, corewar_t *global)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->carry = prog->carry;
    my_strcpy(prog->comment, new->comment);
    new->content = malloc(sizeof(char) * prog->size);
    copy_content(new->content, global->memory, prog->size, prog->address);
    new->id = prog->id;
    new->last_execute = prog->last_execute;
    new->live_call_cyle = prog->live_call_cyle;
    my_strcpy(prog->name, new->name);
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    copy_registers(new->registers, prog->registers, REG_NUMBER);
    new->size = prog->size;
    return new;
}

void e_fork(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    int arg = get_arg_value(global, DIR2, address + 1, prog);
    prog_t *new = create_prog_copy(prog, global);

    new->address = address + prog->size + arg % IDX_MOD;
    new->pc = prog->pc + arg % IDX_MOD;
    place_prog_at(global, new, new->address);
    add_prog(global, new);
    add_pc(&prog->pc, 3);
}
