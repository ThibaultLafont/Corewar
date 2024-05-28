/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_strncat.c
*/

#include <stdio.h>
#include <stddef.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int lendest = my_strlen(dest);
    int i = 0;

    for (i = 0; i < nb && src[i] != '\0'; i++){
        dest[lendest + i] = src[i];
    }
    dest[lendest + i] = '\0';
    return dest;
}
