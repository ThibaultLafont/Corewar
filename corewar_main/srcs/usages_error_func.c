/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** usages_error_func.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "corewar.h"

void clear_terminal(void)
{
    my_putstr("\033[H\033[J");
}

void print_command_line_usage(void)
{
    my_putstr(GREEN);
    my_putstr(BOLD);
    my_putstr("~/B-CPE-200> ");
    my_putstr(RESET);
    my_putstr("./corewar -h");
}

void print_command_usage(void)
{
    my_putstr(RED);
    my_putstr(BOLD);
    my_putstr("\n\nUSAGE\n");
    my_putstr(RESET);
    my_putstr("./corewar [ " YELLOW " " BOLD "-dump nbr_cycle" RESET "]"
        "[[ " YELLOW " " BOLD "-n prog_number" RESET "]"
        "[ " YELLOW " " BOLD "-a load_address" RESET " ");
    my_putstr(CYAN);
    my_putstr(BOLD);
    my_putstr("prog_name");
    my_putstr(RESET);
    my_putstr("] ...\n\n");
}

void print_description(void)
{
    my_putstr(RED);
    my_putstr(BOLD);
    my_putstr("DESCRIPTION\n");
    my_putstr(RESET);
    my_putstr("" BOLD "-dump nbr_cycle" RESET "\n"
        "dumps the memory after the nbr_cycle execution"
        " (if the round isn’t"
        " already over) with the following format:\n32 bytes/line in"
        " hexadecimal (A0BCDEFE1DD3...)"
        "\n\n" BOLD "-n prog_number sets the next program’s number."
        "" RESET "\n\nBy default, the first free number in the"
        " parameter order\n\n"
        "" BOLD "-a load_address sets the next program’s loading address."
        "" RESET "\n\nWhen no address is specified,"
        " optimize the addresses so that the processes are as"
        " far away from each other as"
        " possible.\nThe addresses are MEM_SIZE modulo.\n");
}

int usage(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        clear_terminal();
        print_command_line_usage();
        print_command_usage();
        print_description();
        return 0;
    }
    return 1;
}
