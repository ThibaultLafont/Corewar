/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** dump_arg.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "corewar.h"

/**
 * Sets the dump value and updates the number of cycles to dump.
 *
 * @param value The dump value as a string.
 * @param infos The arguments information structure.
 * @return 0 if successful, otherwise an error code.
 */
int dump_arg(char *value, args_infos_t *infos)
{
    long cycles = 0;

    for (int i = 0; value[i] != '\0'; i++) {
        if (!((value[i] >= 'A' && value[i] <= 'F') ||
            (value[i] >= '0' && value[i] <= '9') ||
            (value[i] >= 'a' && value[i] <= 'f')))
        return (print_error("Value Error: Invalid dump value.\n"));
    }
    cycles = my_getnbr(my_convert_base(value,
    "0123456789ABCDEF", "0123456789"));
    if (cycles <= 0)
        return (print_error("Value Error: Invalid dump value.\n"));
    if (infos->dump != NULL)
        free(infos->dump);
    infos->dump = my_strdup(value);
    infos->global->nbr_cycle_dump = cycles;
    return 0;
}
