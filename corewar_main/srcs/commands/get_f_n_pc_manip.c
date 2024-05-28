/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** get_f_n_pc_manip.c
*/

#include "cmd.h"
#include "corewar.h"

int get_new_adress(prog_t *prog)
{
    return select_address(prog->address + prog->pc);
}

int get_command_duration(int id)
{
    if (id < 1 || id > 16)
        return -1;
    return CMDS[id - 1].duration;
}

void add_pc(int *pc, int nb)
{
    *pc = (*pc + nb) % ONE_MORE_THAN_MAX_USHORT;
}

int select_address(int address)
{
    address %= MEM_SIZE;
    if (address < 0)
        address += MEM_SIZE;
    return address;
}

int get_type_size(arg_type_t type)
{
    switch (type) {
    case REG:
        return (T_REG);
        break;
    case IND:
        return (T_IND);
        break;
    case DIR2:
        return (T_DIR2);
        break;
    case DIR4:
        return (T_DIR4);
        break;
    }
    return 0;
}
