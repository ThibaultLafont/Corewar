/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** or.c
*/

#include "cmd.h"

/**
 * Performs the bitwise OR operation on two arguments and stores the result in a register.
 * Updates the program counter accordingly.
 *
 * @param global The global state of the Corewar virtual machine.
 * @param prog The program executing the instruction.
 */
void e_or(corewar_t *global, prog_t *prog)
{
    int address = get_new_adress(prog);
    arg_type_t args[3] = {get_argument_type(global, address, 1),
    get_argument_type(global, address, 2), REG};
    int first_arg = get_arg_value_mod(global, args[0], address + 2, prog);
    int first_size = get_type_size(args[0]);
    int second_arg =
    get_arg_value_mod(global, args[1], address + 2 + first_size, prog);
    int second_size = get_type_size(args[1]);
    int reg =
    global->memory[select_address(address + 2 + first_size + second_size)];
    int result = first_arg | second_arg;

    prog->registers[reg - 1] = result;
    prog->carry = (result == 0) ? 1 : 0;
    write_new_pc(prog, args, 1);
}
