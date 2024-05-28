/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** init_ncurses.c
*/

#include "corewar.h"
#include <stdbool.h>

void init_colors(void)
{
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void init_ncurses(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
    init_colors();
}

void end_ncurses(void)
{
    endwin();
}
