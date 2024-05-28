/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_op.c
*/

#include "cmd.h"
#include "my.h"
#include "corewar.h"

const instruction_t CMDS[] = {
    {1, 10, 0, 1, {{DIR4}}, &e_live},
    {2, 5, 1, 2, {{DIR4, IND}, {REG}}, &e_ld},
    {3, 5, 1, 2, {{REG}, {IND, REG}}, &e_st},
    {4, 10, 1, 3, {{REG}, {REG}, {REG}}, &e_add},
    {5, 10, 1, 3, {{REG}, {REG}, {REG}}, &e_sub},
    {6, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG}}, &e_and},
    {7, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG}}, &e_or},
    {8, 6, 1, 3, {{REG, DIR4, IND}, {REG, DIR4, IND}, {REG}}, &e_xor},
    {9, 20, 0, 1, {{DIR2}}, &e_zjump},
    {10, 25, 1, 3, {{REG, DIR2, IND}, {DIR2, REG}, {REG}}, &e_ldi},
    {11, 25, 1, 3, {{REG}, {REG, DIR2, IND}, {DIR2, REG}}, &e_sti},
    {12, 800, 0, 1, {{DIR2}}, &e_fork},
    {13, 10, 1, 2, {{DIR4, IND}, {REG}}, &e_lld},
    {14, 50, 1, 3, {{REG, DIR2, IND}, {REG, DIR2}, {REG}},
        &e_lldi},
    {15, 1000, 0, 1, {{DIR2}}, &e_lfork},
    {16, 2, 1, 1, {{REG}}, &e_aff}
};
