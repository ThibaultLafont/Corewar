/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** add_char_pos.c
*/

#include <stdlib.h>
#include "my.h"

char *add_char_pos(char *str, char c, int position)
{
    int len = my_strlen(str);
    char *result = malloc(sizeof(char) * (len + 2));

    if (position) {
        result[0] = c;
        my_strncpy(result + 1, str, len);
    } else {
        my_strncpy(result, str, len);
        result[len] = c;
    }
    result[len + 1] = '\0';
    free(str);
    return result;
}
