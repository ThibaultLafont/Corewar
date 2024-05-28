/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_getnbr.c
*/

#include "my.h"

int is_nb(char symbol)
{
    if (symbol >= 48 && symbol <= 57)
        return (1);
    return (0);
}

long execute_calcul(int field, int last, char *str, int negative)
{
    int pow = 1;
    long result = 0;
    int letter = 0;

    for (int y = last; y >= field; y--) {
        letter = (str[y] - 48) * pow;
        result = result + letter;
        if (negative && result > 2147483648)
            return (0);
        if (!negative && result > 2147483647)
            return (0);
        pow = pow * 10;
    }
    if (negative) {
        result = result * (-1);
    }
    return (result);
}

int process_string(char *str, int *negative, int *field)
{
    while (!is_nb(str[*field])) {
        if (str[*field] == '-') {
            *negative = 1;
            continue;
        }
        if (str[*field] == '+')
            *negative = 0;
        (*field)++;
    }
    return (*field);
}

int find_last_digit(char *str, int field, int size, int *last)
{
    for (int i = field; i < size; i++) {
        *last = i;
        if (!is_nb(str[i])) {
            i = 9999999;
            (*last)--;
        }
    }
    return (*last);
}

int my_getnbr(char *str)
{
    int negative = 0;
    int field = 0;
    int last = 0;
    int size = my_strlen(str);

    process_string(str, &negative, &field);
    find_last_digit(str, field, size, &last);
    return (execute_calcul(field, last, str, negative));
}
