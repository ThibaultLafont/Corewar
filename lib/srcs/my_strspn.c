/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_strspn.c
*/

#include "my.h"
#include <stddef.h>

size_t my_strspn(const char *string, char *valid_chars)
{
    size_t i = 0;

    while (string[i] && my_strchr(valid_chars, string[i]) != NULL)
        i++;
    return i;
}
