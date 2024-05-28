/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** load_address_arg.c
*/

#include <stddef.h>
#include "corewar.h"
#include "my.h"

int check_already_use(long nb, corewar_t *global)
{
    if (!is_prog_address_valid(global, nb))
        return (print_error("Duplication Error: This load address is "
        "already used.\n"));
}

int load_adress_arg(char *value, args_infos_t *infos)
{
    long nb = -1;

    if (infos->load_addres != NULL)
        return (print_error("Value Error: Bad address argument placement.\n"));
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] < '0' && value[i] > '9')
            return (print_error("Value Error: Invalid load_address value.\n"));
    }
    if (my_strcmp(value, "0") == 0) {
        nb = 0;
    } else {
        nb = my_getnbr(value);
        if (nb == 0)
            return (print_error("Value Error: Invalid load_address value.\n"));
    }
    if (nb % MEM_SIZE != 0)
        return (print_error("Value Error: Invalid load_address value.\n"));
    if (check_already_use(nb, infos->global) == FAILURE)
        return FAILURE;
    infos->load_addres = my_strdup(value);
}
