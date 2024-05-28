/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** ncurses.h
*/

#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 128

typedef struct terminal_s {
    int x;
    int y;
} terminal_t;

void init_ncurses(void);
void end_ncurses(void);
