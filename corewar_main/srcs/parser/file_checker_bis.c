/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** file_checker_bis.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>
#include "corewar.h"

int check_file_signature(char *buffer)
{
    uint32_t magic = (unsigned char)buffer[0] << 24 |
    (unsigned char)buffer[1] << 16 |
    (unsigned char)buffer[2] << 8 |
    (unsigned char)buffer[3];

    if (magic != COREWAR_EXEC_MAGIC)
        return (print_error("Value Error: Incorrect magic number.\n"));
    return 0;
}

int verify_file(char *path, char **main_buffer)
{
    FILE *file = open_file(path);
    size_t size = get_file_size(path);
    char *buffer = allocate_buffer(size);

    if (file == NULL || buffer == NULL)
        return FAILURE;
    read_file(file, buffer, size);
    check_file_signature(buffer);
    *main_buffer = buffer;
    fclose(file);
    return 0;
}
