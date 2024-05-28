/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** lfork.c
*/

#include "cmd.h"

/**
 * Executes the lfork instruction.
 * 
 * This instruction creates a new process that is a copy of the current process,
 * except for its program counter (pc) and address. The new process is placed at
 * the specified address and its pc is set to the current pc plus the specified argument.
 * 
 * @param global The global state of the Corewar game.
 * @param prog The current process executing the instruction.
 */
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
