/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_str_isalpha.c
*/

#include <stdio.h>
#include <stdbool.h>

bool locase(char c)
{
    if (c < 123 && c > 96)
        return true;
    return false;
}

bool upcase(char c)
{
    if (c < 91 && c > 64)
        return true;
    return false;
}

bool isaletter(char c)
{
    if (locase(c) || upcase(c))
        return true;
    return false;
}

int my_str_isalpha(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (!(isaletter(str[i])))
            return 0;
    }
    return 1;
}
