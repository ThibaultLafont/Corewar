/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_putstr_error(char *str)
{
    write(2, str, my_strlen(str));
}
