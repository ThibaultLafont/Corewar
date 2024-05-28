/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_str_isupper.c
*/

#include <stdio.h>
#include <stdbool.h>

bool uppercase(char c)
{
    if (c < 91 && c > 64)
        return true;
    return false;
}

int my_str_isupper(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (!(uppercase(str[i])))
            return 0;
    }
    return 1;
}
