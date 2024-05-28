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

/**
 * @brief
 * Checks the magic number of the file buffer.
 *
 * @param buffer The buffer containing the file data.
 * @return 0 if the magic number is correct, otherwise an error code.
 */
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

/**
 * @brief
 * Verifies the file at the given path and stores its contents in the main buffer.
 *
 * @param path The path to the file.
 * @param main_buffer A pointer to the main buffer where the file contents will be stored.
 * @return 0 if the file is successfully verified, otherwise an error code.
 */
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
