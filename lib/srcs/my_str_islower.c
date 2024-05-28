/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_str_islower.c
*/

#include <stdio.h>
#include <stdbool.h>

bool lowercase(char c)
{
    if (c > 96 && c < 122)
        return true;
    return false;
}

int my_str_islower(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (!(lowercase(str[i])))
            return 0;
    }
    return 1;
}
