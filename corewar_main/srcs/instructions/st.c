/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** st.c
*/

#include "cmd.h"

/**
 * @brief Executes the st instruction.
 *
 * This function is responsible for executing the st instruction in the Corewar game.
 * The st instruction stores the value of a register into either another register or a memory address.
 *
 * @param global A pointer to the global state of the Corewar game.
 * @param prog A pointer to the current program executing the instruction.
 */
void e_st(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {REG, get_argument_type(global, address, 2), NO};
    int reg = get_arg_value_mod(global, REG, address + 2, prog);
    int second_arg = get_arg_value_mod(global, args[1], address + 3, prog);

    if (args[1] == REG) {
        second_arg = global->memory[select_address(address + 3)];
        prog->registers[second_arg - 1] = reg;
    } else
        write_4bytes(global,
        select_address(address + second_arg % IDX_MOD), reg);
    prog->carry = (reg == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
