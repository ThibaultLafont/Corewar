/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** op.c
*/

#include "corewar.h"
#include "op.h"
#include <strings.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <signal.h>

op_t *return_op_table_first_half(op_t *op_tab)
{
    op_tab[0] = (op_t){"live", 1, {T_DIR}, 1, 10, "alive"};
    op_tab[1] = (op_t){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"};
    op_tab[2] = (op_t){"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"};
    op_tab[3] = (op_t){"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"};
    op_tab[4] = (op_t){"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"};
    op_tab[5] = (op_t){"and", 3,
    {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
    6, 6, "et (and  r1, r2, r3   r1&r2 -> r3"};
    op_tab[6] = (op_t){"or", 3,
    {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3"};
    op_tab[7] = (op_t){"xor", 3,
    {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
    8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3"};
    return op_tab;
}

op_t *return_op_table_second_half(op_t *op_tab)
{
    op_tab[8] = (op_t){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"};
    op_tab[9] = (op_t){"ldi", 3,
    {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, "load index"};
    op_tab[10] = (op_t){"sti", 3,
    {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, "store index"};
    op_tab[11] = (op_t){"fork", 1, {T_DIR}, 12, 800, "fork"};
    op_tab[12] = (op_t){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"};
    op_tab[13] = (op_t){"lldi", 3,
    {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, "long load index"};
    op_tab[14] = (op_t){"lfork", 1, {T_DIR}, 15, 1000, "long fork"};
    op_tab[15] = (op_t){"aff", 1, {T_REG}, 16, 2, "aff"};
    op_tab[16] = (op_t){0, 0, {0}, 0, 0, 0};
    return op_tab;
}

op_t *init_table(void)
{
    op_t *op_tab = malloc(sizeof(op_t) * 17);

    return_op_table_first_half(op_tab);
    return_op_table_second_half(op_tab);
    return op_tab;
}
