/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_str_isnum.c
*/

#include <stdio.h>
#include <stdbool.h>

bool isnumber(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    return false;
}

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (!(isnumber(str[i])))
            return 0;
    }
    return 1;
}
