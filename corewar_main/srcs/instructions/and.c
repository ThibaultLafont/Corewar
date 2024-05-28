/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** and.c
*/

#include "cmd.h"

/**
** Retrieves the value of the first argument for the 'and' instruction.
** @param global The global structure containing the program and memory information.
** @param prog The program structure containing the program's registers and other data.
** @param address The current address of the instruction.
** @param args The array of argument types.
** @return The value of the first argument.
*/
int get_first_arg_and(corewar_t *global, prog_t *prog,
    int address, arg_type_t *args)
{
    return get_arg_value_mod(global, args[0], address + 2, prog);
}

/**
** Retrieves the value of the register for the 'and' instruction.
** @param global The global structure containing the program and memory information.
** @param address The current address of the instruction.
** @param first_size The size of the first argument.
** @param second_size The size of the second argument.
** @return The value of the register.
*/
int get_reg_and(corewar_t *global, int address,
    int first_size, int second_size)
{
    return global->memory[select_address(address + 2 +
    first_size + second_size)];
}

/**
 * @brief
** Updates the program's register and carry flag with the given result.
** @param prog The program structure containing the program's registers and other data.
** @param reg The register to update.
** @param result The result of the 'and' operation.
*/
void update(prog_t *prog, int reg, int result)
{
    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
}

/**
 * @brief
** Executes the 'and' instruction.
** @param global The global structure containing the program and memory information.
** @param prog The program structure containing the program's registers and other data.
*/
void e_and(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int first_arg = get_first_arg_and(global, prog, address, args);
    int first_size = get_type_size(args[0]);
    int second_arg =
    get_arg_value_mod(global, args[1], address + 2 + first_size, prog);
    int second_size = get_type_size(args[1]);
    int reg = get_reg_and(global, address, first_size, second_size);
    int result = first_arg & second_arg;

    update(prog, reg, result);
    write_new_pc(prog, args, 1);
}
