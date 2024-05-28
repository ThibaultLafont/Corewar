/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_getlongnbr.c
*/

#include "my.h"

long calcul_sign(char const *str, long value)
{
    for (int j = 0; str[j] == '+' || str[j] == '-'; j++)
        if (str[j] == '-')
            value = value * -1;
    return (value);
}

long my_getlongnbr(char const *str)
{
    long value = 0;
    int pos = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 48 && str[i] != '-' && str[i] != '+') ||
        str[i] > 57 || (str[i] < 48 && pos == 1))
            return (calcul_sign(str, value));
        if (str[i] > 47 && str[i] < 58) {
            pos = 1;
            value = (value * 10) + (str[i] - 48);
        }
    }
    return (calcul_sign(str, value));
}
