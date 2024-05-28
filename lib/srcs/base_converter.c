/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_convert_base.c
*/

#include <stdlib.h>
#include "my.h"

int get_basic_value(char c, char *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (c == base[i])
            return (i);
    }
    return 0;
}

int put_base_ten(char *nbr, char *base_from)
{
    int calcul = 0;
    int pow = 1;

    for (int i = my_strlen(nbr) - 1; i >= 0; i--) {
        calcul += get_basic_value(nbr[i], base_from) * pow;
        pow *= my_strlen(base_from);
    }
    return calcul;
}

char *put_base_other(int nb, char *base_to)
{
    char *result = malloc(sizeof(char));
    int calcul;

    result[0] = '\0';
    while (nb > 0) {
        calcul = nb % my_strlen(base_to);
        result = add_char_pos(result, base_to[calcul], 1);
        nb = nb / my_strlen(base_to);
    }
    return result;
}

char *int_to_string(int num)
{
    char *str;
    int temp = num;
    int length = 0;

    do {
        length++;
        temp /= 10;
    } while (temp > 0);
    str = malloc(length + 1);
    str[length] = '\0';
    do {
        length--;
        str[length] = '0' + (num % 10);
        num /= 10;
    } while (num > 0);
    return str;
}

char *my_convert_base(char *nbr, char *base_from, char *base_to)
{
    int base_ten;
    char *result;

    if (my_strcmp(base_from, base_to) == 0)
        return (nbr);
    base_ten = put_base_ten(nbr, base_from);
    if (my_strcmp(base_to, "0123456789") == 0) {
        result = int_to_string(base_ten);
    } else {
        result = put_base_other(base_ten, base_to);
    }
    return result;
}
