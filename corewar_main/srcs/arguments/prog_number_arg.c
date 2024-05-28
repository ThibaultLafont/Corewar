/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** prog_number_arg.c
*/

#include <stddef.h>
#include "my.h"
#include "corewar.h"

int check_already_used(corewar_t *global, long nb)
{
    if (!is_prog_id_valid(global, nb))
        return (print_error("Dupliacation Error: "
        "This program number is already used.\n"));
}

/**
 * Sets the program number argument value.
 * 
 * @param value The value of the program number argument.
 * @param infos The arguments information structure.
 * @return Returns 0 on success, -1 on error.
 */
int prog_number_arg(char *value, args_infos_t *infos)
{
    long nb = -1;

    if (infos->prog_nbr != NULL)
        return (print_error("Value Error: Bad prog_number "
        "argument placement.\n"));
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] < '0' && value[i] > '9')
            return (print_error("Type Error: Invalid prog_number value.\n"));
    }
    if (my_strcmp(value, "0") == 0) {
        infos->prog_nbr = my_strdup(value);
    } else {
        nb = my_getnbr(value);
        if (nb == 0)
            return (print_error("Type Error: Invalid prog_number value.\n"));
        infos->prog_nbr = my_strdup(value);
    }
    check_already_used(infos->global, nb);
}
