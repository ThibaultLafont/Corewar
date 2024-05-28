/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** write_pc.c
*/

#include "cmd.h"
#include "corewar.h"

void write_4bytes(corewar_t *global, int address, int value, int prog_id)
{
    int first_value = (value >> 24) & MAX_BYTES;
    int second_value = (value >> 16) & MAX_BYTES;
    int third_value = (value >> 8) & MAX_BYTES;
    int fourth_value = value & MAX_BYTES;

    global->memory[select_address(address)] = first_value;
    global->memory[select_address(address + 1)] = second_value;
    global->memory[select_address(address + 2)] = third_value;
    global->memory[select_address(address + 3)] = fourth_value;
    global->display[select_address(address)] = prog_id + '0' + 1;
    global->display[select_address(address + 1)] = prog_id + '0' + 1;
    global->display[select_address(address + 2)] = prog_id + '0' + 1;
    global->display[select_address(address + 3)] = prog_id + '0' + 1;
}

int calculate_add(int add, arg_type_t args[3], int has_ocp)
{
    for (int i = 0; i < 3; i++)
        switch (args[i]) {
            case REG:
                add += T_REG;
                break;
            case IND:
                add += T_IND;
                break;
            case DIR2:
                add += T_DIR2;
                break;
            case DIR4:
                add += T_DIR4;
                break;
            default:
                break;
        }
    if (has_ocp)
        add += 1;
    return add;
}

void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp)
{
    int add = 1;

    add = calculate_add(add, args, has_ocp);
    add_pc(&prog->pc, add);
}
