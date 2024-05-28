/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int len;
    char *result;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = '\0';
    return (result);
}

char *my_strndup(char *str, int len)
{
    char *result;

    if (str == NULL)
        return (NULL);
    result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        result[i] = str[i];
    result[len] = '\0';
    return (result);
}
