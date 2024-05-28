/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** fork.c
*/

#include <stdlib.h>
#include "my.h"
#include "cmd.h"

/**
 * Copies the contents of one array to another.
 *
 * @param dest The destination array where the contents will be copied to.
 * @param src The source array from which the contents will be copied.
 * @param size The number of elements to be copied.
 */
void copy_registers(int *dest, int *src, int size)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

/**
 * Copies the content from the source array to the destination array starting from the specified address.
 *
 * @param dest The destination array where the content will be copied to.
 * @param src The source array from which the content will be copied.
 * @param size The number of elements to be copied.
 * @param address The starting address from where the content will be copied.
 */
void copy_content(char *dest, int *src, int size, int address)
{
    for (int i = 0; i < size; i++)
        dest[i] = src[select_address(address + i)];
}

/**
 * Creates a copy of a program.
 *
 * @param prog The program to be copied.
 * @param global The global state of the corewar.
 * @return A pointer to the newly created copy of the program.
 */
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

/**
 * @brief Executes the fork instruction.
 *
 * This function creates a new process by duplicating the current process.
 * The new process is placed at a specified address calculated based on the argument value.
 * The program counter (pc) of the new process is also updated accordingly.
 *
 * @param global A pointer to the global state of the corewar.
 * @param prog A pointer to the current process.
 */
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
