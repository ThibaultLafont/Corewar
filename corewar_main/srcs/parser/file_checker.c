/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** file_checker.c
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

int get_file_size(char *file_path)
{
    struct stat st;

    if (stat(file_path, &st) < 0) {
        return (print_error("Read Error: Can't get file size.\n"));
    }
    if (st.st_size > INT_MAX) {
        return (print_error("Size Error: File is too big.\n"));
    }
    return (int)st.st_size;
}

FILE *open_file(char *path)
{
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        print_error("File Error: Can't open file.\n");
        return NULL;
    }
    return file;
}

char *allocate_buffer(size_t size)
{
    char *buffer = malloc(sizeof(char) * (size + 1));

    if (buffer == NULL) {
        print_error("Memory Error: Allocation problem.\n");
        return NULL;
    }
    return buffer;
}

int read_file(FILE *file, char *buffer, size_t size)
{
    if (fread(buffer, sizeof(char), size, file) != size)
        return (print_error("File Error: Can't read file.\n"));
    buffer[size] = '\0';
    return 0;
}
