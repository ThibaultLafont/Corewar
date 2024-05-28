/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** xor.c
*/

#include "cmd.h"

/**
 * Retrieves the value of the first argument for the XOR instruction.
 *
 * This function takes in the global state, the current program, the argument types,
 * and the current address. It uses the get_arg_value_mod() function to calculate
 * the value of the first argument based on its type and addressing mode.
 *
 * @param global The global state of the Corewar virtual machine.
 * @param prog The current program being executed.
 * @param args An array of argument types.
 * @param address The current address in memory.
 * @return The value of the first argument.
 */
int get_first_arg(corewar_t *global, prog_t *prog,
    arg_type_t *args, int address)
{
    int first_arg = get_arg_value_mod(global, args[0], address + 2, prog);

    return first_arg;
}

/**
 * Retrieves the value of a register from the memory.
 *
 * @param global The global structure containing the memory.
 * @param address The address of the register in the memory.
 * @param first_size The size of the first operand.
 * @param second_size The size of the second operand.
 * @return The value of the register.
 */
int get_reg(corewar_t *global, int address, int first_size, int second_size)
{
    int reg =
    global->memory[select_address(address + 2 + first_size + second_size)];

    return reg;
}

/**
 * Updates the program state after performing an XOR operation.
 *
 * This function updates the specified program's register, carry flag, and program counter
 * based on the result of the XOR operation.
 *
 * @param prog The program to update.
 * @param reg The register to update.
 * @param result The result of the XOR operation.
 * @param args The arguments used in the XOR operation.
 */
void update_prog(prog_t *prog, int reg, int result, arg_type_t *args)
{
    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}

/**
 * Performs the XOR (exclusive OR) operation on two arguments and stores the result in a register.
 * 
 * @param global The global state of the Corewar program.
 * @param prog The current program being executed.
 */
void e_xor(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int first_arg = get_first_arg(global, prog, args, address);
    int first_size = get_type_size(args[0]);
    int second_arg =
    get_arg_value_mod(global, args[1], address + 2 + first_size, prog);
    int second_size = get_type_size(args[1]);
    int reg = get_reg(global, address, first_size, second_size);
    int result = first_arg ^ second_arg;

    update_prog(prog, reg, result, args);
}
