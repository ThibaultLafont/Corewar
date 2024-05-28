/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** my_op.c
*/

#include "cmd.h"
#include "my.h"
#include "corewar.h"

/*
 * 1. Opcode of the command
 * 2. Number of cycles that the command takes to execute
 * 3. A boolean indicating whether the instruction uses an encoding byte or t
 * 4. Number of arguments that the command takes
 * 5. Array of argument types that the command can take
 * 6. Pointer to the function that implements the command
 *
 * DIR is defined as a type of argument that a command can take.
 * In the context of the CMDS array, DIR2 and DIR4 are used to represent a
 * direct argument of 2 bytes and 4 bytes respectively.
 * This is in contrast to the rmal DIR in op.h,
 * which doesn't specify the size of the direct argument.
 */
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
