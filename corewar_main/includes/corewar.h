/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** corewar.h
*/

#pragma once
#include <stddef.h>
#include <stdio.h>
#include "op.h"

#define MAX_USHORT 0xFFFF
#define ONE_MORE_THAN_MAX_USHORT 0x10000
#define MAX_BYTES 0xFF
#define HIGH_BYTE 0xFF00

#define FAILURE 84

typedef int arg_type_t;
typedef int argc_t;
typedef char **argv_t;
typedef int size__t;

typedef struct prog_s {
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int pc;
    int carry;
    long id;
    int live_call_cyle;
    int address;
    long size;
    char *content;
    int *registers;
    int last_execute;
} prog_t;

typedef struct corewar_s {
    argc_t argc;
    argv_t argv;
    long nbr_cycle_dump;
    long cycle;
    int cycles_to_die;
    int *memory;
    char *last_alive;
    int last_live_id;
    int live_calls;
    prog_t **progs;
} corewar_t;

typedef struct args_infos_s {
    corewar_t *global;
    char *dump;
    char *prog_nbr;
    char *load_addres;
} args_infos_t;

/**
 * @brief Dumps the memory contents to the standard output.
 *
 * @param value The value of the dump argument.
 * @param infos The argument information structure.
 * @return int Returns 0 on success, -1 on failure.
 */
int dump_arg(char *value, args_infos_t *infos);

/**
 * @brief Sets the program number for a given program.
 *
 * @param value The value of the program number argument.
 * @param infos The argument information structure.
 * @return int Returns 0 on success, -1 on failure.
 */
int prog_number_arg(char *value, args_infos_t *infos);

/**
 * @brief Sets the load address for a given program.
 *
 * @param value The value of the load address argument.
 * @param infos The argument information structure.
 * @return int Returns 0 on success, -1 on failure.
 */
int load_adress_arg(char *value, args_infos_t *infos);

/**
 * @brief Prints the usage information for the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return int Returns 0 on success, -1 on failure.
 */
int usage(int argc, char **argv);

/**
 * @brief Prints an error message to the standard error output.
 *
 * @param msg The error message to print.
 * @return int Returns 0 on success, -1 on failure.
 */
int print_error(char *msg);

/**
 * @brief Manages all the command-line arguments.
 *
 * @param global The global structure containing program information.
 * @return int Returns 0 on success, -1 on failure.
 */
int manage_all_args(corewar_t *global);

/**
 * @brief Parses a .cor file and extracts program information.
 *
 * @param file The path to the .cor file.
 * @param prog_nbr The program number.
 * @param load_address The load address.
 * @param global The global structure containing program information.
 * @return int Returns 0 on success, -1 on failure.
/**
 * Parses a .cor file and extracts information such as
 * program number, load address, and global data.
 * @param file The path to the .cor file to be parsed.
 * @param prog_nbr A pointer to store the program number
 * extracted from the file.
 * @param load_address A pointer to store the load address
 * extracted from the file.
 * @param global A pointer to the global data structure.
 * @return Returns 0 on success, -1 on failure.
 */
int parse_cor_file(char *file, char *prog_nbr, char *load_address,
    corewar_t *global);

/**
 * Verifies the integrity of a file by checking its path and reading its
 * contents into a buffer.
 * @param path The path to the file to be verified.
 * @param buffer A pointer to store the file contents.
 * @return Returns 0 on success, -1 on failure.
 */
int verify_file(char *path, char **buffer);

/**
 * The main loop cycle of the corewar program.
 * @param global A pointer to the global data structure.
 * @return Returns 0 on success, -1 on failure.
 */
int main_loop_cycle(corewar_t *global);

/**
 * Displays the winner of the corewar program.
 * @param global A pointer to the global data structure.
 */
void show_winner(corewar_t *global);

/**
 * Executes the current instruction in the corewar program.
 * @param global A pointer to the global data structure.
 */
void exec_instruction(corewar_t *global);

/**
 * Verifies the size of the corewar program.
 * @param global A pointer to the global data structure.
 * @return Returns 0 if the size is valid, -1 if the size is invalid.
 */
int verif_size(corewar_t *global);

/**
 * Retrieves the sizes of all programs in the corewar program.
 * @param global A pointer to the global data structure.
 * @return Returns 0 on success, -1 on failure.
/**
 * @file corewar.h
 * @brief Header file containing function declarations for
 * managing programs in the corewar simulation.
 */

/**
 * @brief Calculates the total size of all programs in the global structure.
 * @param global The global structure containing the programs.
 * @return The total size of all programs.
 */
int get_all_progs_sizes(corewar_t *global);

/**
 * @brief Adds a program to the global structure.
 * @param global The global structure to add the program to.
 * @param prog The program to add.
 */
void add_prog(corewar_t *global, prog_t *prog);

/**
 * @brief Destroys a program in the global structure.
 * @param global The global structure containing the program.
 * @param prog The program to destroy.
 */
void destroy_prog(corewar_t *global, prog_t *prog);

/**
 * @brief Gets a valid ID for a program in the global structure.
 * @param global The global structure.
 * @return A valid ID for a program.
 */
int get_valid_id(corewar_t *global);

/**
 * @brief Checks if a program ID is valid in the global structure.
 * @param global The global structure.
 * @param id The ID to check.
 * @return 1 if the ID is valid, 0 otherwise.
 */
int is_prog_id_valid(corewar_t *global, long id);

/**
 * @brief Checks if a program address is valid in the global structure.
 * @param global The global structure.
 * @param address The address to check.
 * @return 1 if the address is valid, 0 otherwise.
 */
int is_prog_address_valid(corewar_t *global, int address);

/**
 * @brief Deletes dead programs from the global structure.
 * @param global The global structure.
 */
void delete_dead_progs(corewar_t *global);

/**
 * @brief Destroys all programs in the global structure.
 * @param global The global structure.
 * @return The number of destroyed programs.
 */
int destroy_every_progs(corewar_t *global);

/**
 * @brief Sorts the programs in the global structure based on their IDs.
 * @param global The global structure.
 */
void sort_progs(corewar_t *global);

/**
 * @brief Places the programs in the global structure in the
 * corewar simulation.
 * @param global The global structure.
 * @return 1 if all programs are successfully placed, 0 otherwise.
 */
int place_progs(corewar_t *global);

/**
 * @brief Checks if a program can be placed at a specific address in
 * the corewar simulation.
 * @param global The global structure.
 * @param prog The program to place.
 * @param address The address to place the program at.
 * @return 1 if the program can be placed at the address, 0 otherwise.
 */
int can_place_prog(corewar_t *global, prog_t *prog, int address);

/**
 * @brief Places a program at a specific address in the corewar simulation.
 * @param global The global structure.
 * @param prog The program to place.
 * @param address The address to place the program at.
/**
 * @file corewar.h
 * @brief Header file containing function declarations for the Corewar program.
 */

/**
 * @brief Places a program at a specific address in the global memory.
 *
 * @param global The global memory structure.
 * @param prog The program structure.
 * @param address The address where the program should be placed.
 */
void place_prog_at(corewar_t *global, prog_t *prog, int address);

/**
 * @brief Gets a new address for a program.
 *
 * @param prog The program structure.
 * @return The new address for the program.
 */
int get_new_adress(prog_t *prog);

/**
 * @brief Gets the duration of a command.
 *
 * @param id The ID of the command.
 * @return The duration of the command.
 */
int get_command_duration(int id);

/**
 * @brief Adds a value to the program counter (pc).
 *
 * @param pc The program counter.
 * @param nb The value to add.
 */
void add_pc(int *pc, int nb);

/**
 * @brief Checks if a command is valid at a specific address.
 *
 * @param global The global memory structure.
 * @param address The address to check.
 * @return 1 if the command is valid, 0 otherwise.
 */
int check_cmd(corewar_t *global, int address);

/**
 * @brief Selects the address to execute a command.
 *
 * @param address The address to select.
 * @return The selected address.
 */
int select_address(int address);

/**
 * @brief Gets the type of an argument for a command.
 *
 * @param global The global memory structure.
 * @param cmd_address The address of the command.
 * @param arg The argument index.
 * @return The type of the argument.
 */
arg_type_t get_argument_type(corewar_t *global, int cmd_address, int arg);

/**
 * @brief Gets the value of a 4-byte argument at a specific address.
 *
 * @param global The global memory structure.
 * @param address The address of the argument.
 * @return The value of the argument.
 */
long get_actual_4_bytes(corewar_t *global, int address);

/**
 * @brief Gets the value of a 2-byte argument at a specific address.
 *
 * @param global The global memory structure.
 * @param address The address of the argument.
 * @return The value of the argument.
 */
int get_actual_2_bytes(corewar_t *global, int address);

/**
 * @brief Gets the size of a specific argument type.
 *
 * @param type The argument type.
 * @return The size of the argument type.
 */
int get_type_size(arg_type_t type);

/**
 * @brief Writes a 4-byte value to a specific address in the global memory.
 *
 * @param global The global memory structure.
 * @param address The address to write the value to.
 * @param value The value to write.
 */
void write_4bytes(corewar_t *global, int address, int value);

/**
 * @brief Writes the new program counter (pc) based
 * on the arguments and opcode.
 * @param prog The program structure.
 * @param args The argument types.
 * @param has_ocp Flag indicating if the command has an opcode.
 */
void write_new_pc(prog_t *prog, arg_type_t args[3], int has_ocp);

/**
 * @brief Gets the value of an argument based on its type and address.
 * @param global The global memory structure.
 * @param type The argument type.
 * @param address The address of the argument.
 * @param prog The program structure.
 * @return The value of the argument.
 */
long get_arg_value(corewar_t *global, arg_type_t type,
    int address, prog_t *prog);

/**
 * @brief Retrieves the value of an argument based on its type and address.
 *
 * This function is used to get the value of
 * an argument in the corewar program.
 * It takes a global structure pointer, an argument type, an address,
 * and a program structure pointer as parameters.
 * The function returns the value of the argument.
 *
 * @param global A pointer to the global structure.
 * @param type The type of the argument.
 * @param address The address of the argument.
 * @param prog A pointer to the program structure.
 * @return The value of the argument.
 */
long get_arg_value_mod(corewar_t *global, arg_type_t type,
    int address, prog_t *prog);

/**
 * @brief Clears the terminal screen.
 *
 * This function is used to clear the terminal screen.
 * It does not take any parameters and does not return anything.
 */
void clear_terminal(void);

/**
 * @brief Prints the command line usage.
 *
 * This function is used to print the usage of the command line.
 * It does not take any parameters and does not return anything.
 */
void print_command_line_usage(void);

/**
 * @brief Prints the command usage.
 *
 * This function is used to print the usage of a command.
 * It does not take any parameters and does not return anything.
 */
void print_command_usage(void);

/**
 * @brief Prints the description.
 *
 * This function is used to print the description.
 * It does not take any parameters and does not return anything.
 */
void print_description(void);

/**
 * @brief Prints the winner.
 *
 * This function is used to print the winner of the corewar program.
 * It takes a global structure pointer as a parameter and
 * does not return anything.
 *
 * @param global A pointer to the global structure.
 */
void print_winner(corewar_t *global);

/**
 * @brief Prints a message when there is no winner.
 *
 * This function is used to print a message when there
 * is no winner in the corewar program.
 * It does not take any parameters and does not return anything.
 */
void print_no_winner(void);

/**
 * @brief Frees all allocated memory.
 *
 * This function is used to free all the allocated
 * memory in the corewar program.
 * It takes a global structure pointer as a parameter
 * and does not return anything.
 *
 * @param global A pointer to the global structure.
 */
void free_all(corewar_t *global);

/**
 * @brief Executes the core program.
 *
 * This function is used to execute the core program of the corewar program.
 * It takes a global structure pointer as a parameter and
 * returns an integer value.
 * The function returns 0 if the execution is successful,
 * otherwise it returns -1.
 *
 * @param global A pointer to the global structure.
 * @return 0 if the execution is successful, -1 otherwise.
 */
int core_program(corewar_t *global);

/**
 * @brief Continues the cycle.
 *
 * This function is used to continue the cycle of the corewar program.
 * It takes a global structure pointer as a parameter
 * and returns an integer value.
 * The function returns 0 if the cycle continues, otherwise it returns -1.
 *
 * @param global A pointer to the global structure.
 * @return 0 if the cycle continues, -1 otherwise.
 */
int continue_cycle(corewar_t *global);

/**
 * @brief Frees the program structure.
 *
 * This function is used to free the program structure.
 * It takes a program structure pointer as a parameter
 * and does not return anything.
 *
 * @param prog A pointer to the program structure.
 */
void free_prog(prog_t *prog);

/**
 * @brief Swaps two programs.
 *
 * This function is used to swap two programs in the corewar program.
 * It takes a global structure pointer, and two indices as parameters
 * and does not return anything.
 *
 * @param global A pointer to the global structure.
 * @param idx1 The index of the first program.
 * @param idx2 The index of the second program.
 */
void swap_progs(corewar_t *global, int idx1, int idx2);

/**
 * @brief Parcours the programs.
 *
 * This function is used to parcours the programs in the corewar program.
 * It takes a global structure pointer as a parameter and
 * returns an integer value.
 * The function returns 0 if the parcours is successful,
 * otherwise it returns -1.
 *
 * @param global A pointer to the global structure.
 * @return 0 if the parcours is successful, -1 otherwise.
 */
int parcour_progs(corewar_t *global);
/**
 * @file corewar.h
 * @brief Header file containing function declarations for the corewar program.
 */

/**
 * @brief Checks if a program can be placed at a specific address in memory.
 * @param progp Pointer to the program to be placed.
 * @param prog Pointer to the program being checked against.
 * @param address The address in memory to check.
 * @return 1 if the program can be placed at the address, 0 otherwise.
 */
int test_place(prog_t *progp, prog_t *prog, int address);

/**
 * @brief Places a program in memory at a normal address.
 * @param global Pointer to the global structure.
 * @param space The amount of space to allocate for the program.
 */
void place_normal(corewar_t *global, int space);

/**
 * @brief Prints the alive status of a program.
 * @param prog Pointer to the program.
 */
void print_alive(prog_t *prog);

/**
 * @brief Shows the alive status of all programs.
 * @param prog Pointer to the program.
 * @param global Pointer to the global structure.
 */
void show_alive(prog_t *prog, corewar_t *global);

/**
 * @brief Retrieves the value of two registers and performs a logical
 * AND operation.
 * @param global Pointer to the global structure.
 * @param address The address in memory to retrieve the registers from.
 * @param first_size The size of the first register.
 * @param second_size The size of the second register.
 * @return The result of the logical AND operation.
 */
int get_reg_and(corewar_t *global, int address, int first_size,
    int second_size);

/**
 * @brief Updates the value of a register in a program.
 * @param prog Pointer to the program.
 * @param reg The register to update.
 * @param result The new value for the register.
 */
void update(prog_t *prog, int reg, int result);

/**
 * @brief Retrieves the value of a register from memory.
 * @param global Pointer to the global structure.
 * @param address The address in memory to retrieve the register from.
 * @param first_size The size of the register.
 * @param second_size The size of the register.
 * @return The value of the register.
 */
int get_reg(corewar_t *global, int address, int first_size, int second_size);

/**
 * @brief Updates the value of a register in a program and updates the
 * program's arguments.
 * @param prog Pointer to the program.
 * @param reg The register to update.
 * @param result The new value for the register.
 * @param args Pointer to the program's arguments.
 */
void update_prog(prog_t *prog, int reg, int result, arg_type_t *args);
/**
 * @brief Gets the size of a file.
 *
 * @param file_path The path to the file.
 * @return The size of the file in bytes.
 */
int get_file_size(char *file_path);

/**
 * @brief Reads the contents of a file into a buffer.
 *
 * @param file The file to read from.
 * @param buffer The buffer to store the file contents.
 * @param size The size of the buffer.
 * @return The number of bytes read.
 */
int read_file(FILE *file, char *buffer, size_t size);

/**
 * @brief Checks the file signature.
 *
 * @param buffer The buffer containing the file contents.
 * @return 1 if the file signature is valid, 0 otherwise.
 */
int check_file_signature(char *buffer);

/**
 * @brief Parses the program header.
 *
 * @param file The file to parse.
 * @param prog The program structure to store the parsed header.
 */
void parse_prog_header(char *file, prog_t *prog);

/**
 * @brief Verifies the placing of a program in memory.
 *
 * @param global The global structure containing the memory.
 * @param prog The program structure to verify.
 * @return 1 if the placing is valid, 0 otherwise.
 */
int verify_placing(corewar_t *global, prog_t *prog);

/**
 * @brief Defines the content of a program.
 *
 * @param file The file to read from.
 * @param new The program structure to store the content.
 */
void define_content(char *file, prog_t *new);

/**
 * @brief Checks if a number has already been used.
 *
 * @param global The global structure containing the used numbers.
 * @param nb The number to check.
 * @return 1 if the number has already been used, 0 otherwise.
 */
int check_already_used(corewar_t *global, long nb);

/**
 * @brief Checks if a number has already been used.
 *
 * @param nb The number to check.
 * @param global The global structure containing the used numbers.
 * @return 1 if the number has already been used, 0 otherwise.
 */
int check_already_use(long nb, corewar_t *global);

/**
 * @brief Checks the count of command line arguments.
 *
 * @param argc The number of command line arguments.
 * @param i The index of the current argument.
 * @return 1 if the count is valid, 0 otherwise.
 */
int check_argument_count(int argc, int i);
/**
 * @brief Manages the command line flags.
 *
 * This function takes the command line arguments, the current
 * index, and a structure
 * containing information about the arguments. It processes the
 * flags and updates the
 * information in the structure accordingly.
 *
 * @param argc The number of command line arguments.
 * @param argv An array of strings containing the command line arguments.
 * @param i The current index in the command line arguments array.
 * @param infos A pointer to the structure containing information
 * about the arguments.
 * @return The new index after processing the flags.
 */
int manage_flag(int argc, char **argv, int i, args_infos_t *infos);

/**
 * @brief Manages the file.
 *
 * This function takes the path to a file, a pointer to a
 * structure containing information
 * about the arguments, and a pointer to a global structure.
 * It processes the file and
 * updates the information in the structures accordingly.
 *
 * @param path The path to the file.
 * @param infos A pointer to the structure containing
 * information about the arguments.
 * @param global A pointer to the global structure.
 * @return 0 if successful, -1 otherwise.
 */
int manage_file(char *path, args_infos_t *infos, corewar_t *global);

/**
 * @brief Calculates the address to jump to.
 *
 * This function takes an address, an array of argument types,
 * and a flag indicating
 * whether the instruction has an OCP (Operand Coding Byte).
 * It calculates the address
 * to jump to based on the arguments and the OCP.
 *
 * @param add The base address.
 * @param args An array of argument types.
 * @param has_ocp A flag indicating whether the instruction has an OCP.
 * @return The calculated address.
 */
int calculate_add(int add, arg_type_t args[3], int has_ocp);

/**
 * @brief Verifies the arguments of an instruction.
 *
 * This function takes a command, and three arguments.
 * It verifies whether the arguments
 * are valid for the given command.
 *
 * @param cmd The command.
 * @param first_arg The first argument.
 * @param second_arg The second argument.
 * @param third_arg The third argument.
 * @return 1 if the arguments are valid, 0 otherwise.
 */
int verify_args(int cmd, int first_arg, int second_arg, int third_arg);

/**
 * @brief Checks the OCP (Operand Coding Byte).
 *
 * This function takes a pointer to a global structure and an address.
 * It checks whether
 * the OCP at the given address is valid.
 *
 * @param global A pointer to the global structure.
 * @param address The address to check.
 * @return 1 if the OCP is valid, 0 otherwise.
 */
int check_op_code(corewar_t *global, int address);

/**
 * @brief Gets the value at a given address.
 *
 * This function takes a pointer to a global structure,
 * an address, a command, and an
 * argument. It gets the value at the given address
 * based on the command and argument.
 *
 * @param global A pointer to the global structure.
 * @param address The address to get the value from.
 * @param cmd The command.
 * @param arg The argument.
 * @return The value at the given address.
 */
int get_parcour_value(corewar_t *global, int address, int cmd, int arg);

/**
 * @brief Checks the registers.
 *
 * This function takes a pointer to a global structure and an address.
 * It checks whether
 * the registers at the given address are valid.
 *
 * @param global A pointer to the global structure.
 * @param address The address to check.
 * @return 1 if the registers are valid, 0 otherwise.
 */
int check_registers(corewar_t *global, int address);

/**
 * Executes a calculation based on the given field, last value,
 * string, and negative flag.
 *
 * @param field The field value.
 * @param last The last value.
 * @param str The string to be processed.
 * @param negative The negative flag.
 * @return The result of the calculation.
 */
long execute_calcul(int field, int last, char *str, int negative);

/**
 * Processes a string and updates the negative flag, field value,
 * and last value accordingly.
 *
 * @param str The string to be processed.
 * @param negative A pointer to the negative flag.
 * @param field A pointer to the field value.
 * @return The result of the string processing.
 */
int process_string(char *str, int *negative, int *field);
/**
 * Finds the last digit in a string.
 *
 * This function searches for the last digit in the given string and
 * returns its position.
 *
 * @param str The string to search in.
 * @param field The field to search for the last digit in.
 * @param size The size of the string.
 * @param last A pointer to an integer to store the position of the last digit.
 * @return The position of the last digit, or -1 if no digit is found.
 */
int find_last_digit(char *str, int field, int size, int *last);

/**
 * Allocates a buffer of the specified size.
 *
 * This function dynamically allocates a buffer of the specified size and
 * returns a pointer to it.
 *
 * @param size The size of the buffer to allocate.
 * @return A pointer to the allocated buffer, or NULL if the allocation fails.
 */
char *allocate_buffer(size_t size);

/**
 * Opens a file with the specified path.
 *
 * This function opens a file with the specified path and returns a
 * pointer to the opened file.
 *
 * @param path The path of the file to open.
 * @return A pointer to the opened file, or NULL if the file cannot be opened.
 */
FILE *open_file(char *path);
