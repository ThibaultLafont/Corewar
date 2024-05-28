/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** parser_header.c
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"

static void parse_prog_name(char *file, prog_t *prog)
{
    for (int i = 4; i < 4 + PROG_NAME_LENGTH; i++)
        prog->name[i - 4] = file[i];
    prog->name[PROG_NAME_LENGTH] = '\0';
}

static void parse_prog_comment(char *file, prog_t *prog)
{
    int offset = 12 + PROG_NAME_LENGTH + COMMENT_LENGTH;

    for (int i = 12 + PROG_NAME_LENGTH; i < offset; i++)
        prog->comment[i - 12 - PROG_NAME_LENGTH] = file[i];
    prog->comment[COMMENT_LENGTH] = '\0';
}

static void parse_prog_size(char *file, prog_t *prog)
{
    prog->size = file[4 + PROG_NAME_LENGTH];
    for (int i = 5 + PROG_NAME_LENGTH; i < 12 + PROG_NAME_LENGTH; i++) {
        prog->size = prog->size << 8;
        prog->size += file[i];
    }
}

void parse_prog_header(char *file, prog_t *prog)
{
    parse_prog_name(file, prog);
    parse_prog_comment(file, prog);
    parse_prog_size(file, prog);
}
