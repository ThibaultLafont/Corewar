/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** cmd.h
*/

#pragma once
#include "corewar.h"

#define NO 0
#define REG 1
#define DIR2 2
#define DIR4 4
#define IND 3

typedef struct valid_args_s {
    arg_type_t first_arg;
    arg_type_t second_arg;
    arg_type_t third_arg;
} valid_args_t;

typedef struct instruction_s {
    int id;
    int duration;
    int has_op_code;
    int args_nbr;
    valid_args_t args_types[3];
    void (*exec_function)(corewar_t *, prog_t *);
} instruction_t;

void e_and(corewar_t *global, prog_t *prog);
void e_live(corewar_t *global, prog_t *prog);
void e_sti(corewar_t *global, prog_t *prog);
void e_zjump(corewar_t *global, prog_t *prog);
void e_xor(corewar_t *global, prog_t *prog);
void e_or(corewar_t *global, prog_t *prog);
void e_aff(corewar_t *global, prog_t *prog);
void e_fork(corewar_t *global, prog_t *prog);
void e_lfork(corewar_t *global, prog_t *prog);
void e_ld(corewar_t *global, prog_t *prog);
void e_st(corewar_t *global, prog_t *prog);
void e_ldi(corewar_t *global, prog_t *prog);
void e_lldi(corewar_t *global, prog_t *prog);
void e_add(corewar_t *global, prog_t *prog);
void e_sub(corewar_t *global, prog_t *prog);
void e_lld(corewar_t *global, prog_t *prog);
prog_t *create_prog_copy(prog_t *prog, corewar_t *global);

extern const instruction_t CMDS[];
