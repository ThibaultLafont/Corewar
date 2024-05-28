/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** args_manager.c
*/

#include <stdlib.h>
#include "corewar.h"
#include "my.h"
#include <stdio.h>

int check_argument_count(int argc, int i)
{
    if (i + 1 >= argc)
        return (print_error("Value Error: Invalid number of arguments.\n"));
}

int manage_flag(int argc, char **argv, int i, args_infos_t *infos)
{
    if (check_argument_count(argc, i) == FAILURE)
        return FAILURE;
    if (my_strcmp(argv[i], "-dump") == 0)
        return (dump_arg(argv[i + 1], infos));
    if (my_strcmp(argv[i], "-n") == 0) {
        prog_number_arg(argv[i + 1], infos);
        return 0;
    }
    if (my_strcmp(argv[i], "-a") == 0)
        return (load_adress_arg(argv[i + 1], infos));
    else
        return (print_error("Type Error: Invalid argument.\n"));
    return 0;
}

int manage_file(char *path, args_infos_t *infos, corewar_t *global)
{
    char *buffer;
    int status_verify = 0;
    int status_parse = 0;

    status_verify = verify_file(path, &buffer);
    status_parse =
    parse_cor_file(buffer, infos->prog_nbr, infos->load_addres, global);
    if (status_verify == FAILURE || status_parse == FAILURE)
        return FAILURE;
    if (infos->prog_nbr != NULL) {
        free(infos->prog_nbr);
        infos->prog_nbr = NULL;
    }
    if (infos->load_addres != NULL) {
        free(infos->load_addres);
        infos->load_addres = NULL;
    }
    free(buffer);
    return 0;
}

/**
 * @brief Manages all the arguments passed to the program.
 * 
 * This function iterates through the command line arguments and handles each argument accordingly.
 * It checks if the usage flag is present and returns 1 if it is, indicating that the program should exit.
 * For each argument starting with '-', it calls the `manage_flag` function to handle the flag.
 * For each argument that is not a flag, it calls the `manage_file` function to handle the file.
 * If any of the flag or file management functions return a failure status, this function returns FAILURE.
 * After processing all the arguments, it checks if the `dump` flag is set and frees the memory allocated for it.
 * Finally, it checks if there are at least 2 champions specified and returns an error if not.
 * 
 * @param global A pointer to the `corewar_t` structure containing global variables.
 * @return 0 if all arguments are successfully managed, FAILURE otherwise.
 */
int manage_all_args(corewar_t *global)
{
    args_infos_t infos = {global, NULL, NULL, NULL};
    int status = 0;
    int status_second = 0;

    if (usage(global->argc, global->argv) == 0)
        return 1;
    for (int i = 1; i < global->argc; i++) {
        if (global->argv[i][0] == '-') {
            status = manage_flag(global->argc, global->argv, i, &infos);
            i++;
        } else
            status_second = manage_file(global->argv[i], &infos, global);
        if (status == FAILURE || status_second == FAILURE)
            return FAILURE;
    }
    if (infos.dump != NULL)
        free(infos.dump);
    if (get_all_progs_sizes(global) < 2)
        return (print_error("Arg Error: 2 champions minimum are required.\n"));
    return 0;
}
