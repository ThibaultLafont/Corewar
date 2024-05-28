/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** end_print.c
*/

#include <stdlib.h>
#include "my.h"
#include "corewar.h"

void print_winner(corewar_t *global)
{
    my_putstr("The player ");
    my_putnbr(global->last_live_id);
    my_putstr("(");
    my_putstr(global->last_alive);
    my_putstr(")has won.\n");
}

void print_no_winner(void)
{
    my_putstr("No winner !\n");
}

void show_winner(corewar_t *global)
{
    if (global->last_alive == NULL) {
        print_no_winner();
        return;
    }
    end_ncurses();
    print_winner(global);
    free(global->last_alive);
}
