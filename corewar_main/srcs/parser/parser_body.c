/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** parse_body.c
*/

#include "corewar.h"
#include "my.h"
#include <stdlib.h>

/**
 * Verifies if the program can be placed at the specified address.
 * 
 * @param global The global corewar structure.
 * @param prog The program to be placed.
 * @return 0 if the program can be placed, -1 otherwise.
 */
int verify_placing(corewar_t *global, prog_t *prog)
{
    if (prog->address == -1)
        return 0;
    if (!can_place_prog(global, prog, prog->address))
        return (print_error("Placement Error: Bad program placement.\n"));
    return 0;
}

/**
 * Defines the content of the program based on the file contents.
 * 
 * @param file The contents of the file.
 * @param new The program structure to be updated.
 */
void define_content(char *file, prog_t *new)
{
    int offset = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH;

    new->content = malloc(sizeof(char) * new->size);
    for (int i = 0; i < new->size; i++)
        new->content[i] = file[i + offset + 4];
}

/**
 * Creates a new program structure.
 * 
 * @param prog_nbr The program number.
 * @param load_address The load address of the program.
 * @param global The global corewar structure.
 * @return A pointer to the newly created program structure.
 */
prog_t *create_new_prog(char *prog_nbr, char *load_address, corewar_t *global)
{
    prog_t *new = malloc(sizeof(prog_t));

    new->id = (prog_nbr == NULL) ? get_valid_id(global) :
    my_getlongnbr(prog_nbr);
    if (!is_prog_id_valid(global, new->id)) {
        print_error("Value Error: Bad champion id.\n");
        return NULL;
    }
    new->address = (load_address == NULL) ? -1 : my_getnbr(load_address);
    new->carry = 0;
    new->live_call_cyle = 0;
    new->pc = 0;
    return new;
}

/**
 * Parses the program header and defines the content of the program.
 * 
 * @param file The contents of the file.
 * @param new The program structure to be updated.
 */
static void parse_header_and_define_content(char *file, prog_t *new)
{
    parse_prog_header(file, new);
    define_content(file, new);
}

/**
 * Initializes the registers of the program.
 * 
 * @param new The program structure to be updated.
 */
static void initialize_registers(prog_t *new)
{
    new->registers = malloc(sizeof(int) * REG_NUMBER);
    for (int i = 0; i < REG_NUMBER; i++)
        new->registers[i] = 0;
    new->registers[0] = new->id;
    new->last_execute = -1;
}

/**
 * Verifies the program placement and adds it to the global corewar structure.
 * 
 * @param global The global corewar structure.
 * @param new The program to be verified and added.
 */
void verify_and_add_prog(corewar_t *global, prog_t *new)
{
    verify_placing(global, new);
    add_prog(global, new);
}

/**
 * Parses the contents of a .cor file and adds the program to the global corewar structure.
 * 
 * @param file The contents of the .cor file.
 * @param prog_nbr The program number.
 * @param load_address The load address of the program.
 * @param global The global corewar structure.
 * @return 0 on success, -1 on failure.
 */
int parse_cor_file(char *file, char *prog_nbr,
    char *load_address, corewar_t *global)
{
    prog_t *new = create_new_prog(prog_nbr, load_address, global);

    if (new == NULL)
        return -1;
    parse_header_and_define_content(file, new);
    initialize_registers(new);
    verify_and_add_prog(global, new);
    return 0;
}
