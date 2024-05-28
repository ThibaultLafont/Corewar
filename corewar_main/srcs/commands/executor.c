/*
** EPITECH PROJECT, 2024
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** executor.c
*/

#include "my.h"
#include "cmd.h"

struct command_info {
    int address;
    int value;
    int duration;
};

/**
 * Executes the specified command for a given program.
 *
 * @param global The global state of the Corewar game.
 * @param prog The program for which the command is being executed.
 * @param cmd_info Information about the command to be executed.
 */
void call_command(corewar_t *global, prog_t *prog,
    struct command_info *cmd_info)
{
    if (check_cmd(global, cmd_info->address)) {
        CMDS[cmd_info->value - 1].exec_function(global, prog);
        prog->last_execute = global->cycle;
    } else
        add_pc(&prog->pc, 1);
}

/**
 * Executes a command if the program is ready to execute it.
 *
 * @param global The global state of the Corewar program.
 * @param prog The program that is being executed.
 * @param cmd_info Information about the command to be executed.
 */
void execute_if_ready(corewar_t *global, prog_t *prog,
    struct command_info *cmd_info)
{
    if (prog->last_execute == -1 ||
    ABS(global->cycle - prog->last_execute) >= cmd_info->duration)
        call_command(global, prog, cmd_info);
}

/**
 * Executes the instructions for each program in the global state.
 * 
 * @param global The global state of the corewar program.
 */
void exec_instruction(corewar_t *global)
{
    struct command_info cmd_info;

    if (global->progs == NULL)
        return;
    for (int i = 0; global->progs[i] != NULL; i++) {
        cmd_info.address = get_new_adress(global->progs[i]);
        cmd_info.value = global->memory[cmd_info.address];
        cmd_info.duration = get_command_duration(cmd_info.value);
        if (cmd_info.duration == -1 ||
        cmd_info.value < 1 ||
        cmd_info.value > 16) {
            add_pc(&global->progs[i]->pc, 1);
            continue;
        }
        execute_if_ready(global, global->progs[i], &cmd_info);
    }
}
