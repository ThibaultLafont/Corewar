/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** error_print.c
*/

#include "corewar.h"
#include "my.h"

int print_error(char *msg)
{
    my_putstr_error(msg);
    return FAILURE;
}
