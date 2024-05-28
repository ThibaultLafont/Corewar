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

void call_command(corewar_t *global, prog_t *prog,
    struct command_info *cmd_info)
{
    if (check_cmd(global, cmd_info->address)) {
        CMDS[cmd_info->value - 1].e_func(global, prog);
        prog->last_execute = global->cycle;
    } else
        add_pc(&prog->pc, 1);
}

void execute_if_ready(corewar_t *global, prog_t *prog,
    struct command_info *cmd_info)
{
    if (prog->last_execute == -1 ||
    ABS(global->cycle - prog->last_execute) >= cmd_info->duration) {
        call_command(global, prog, cmd_info);
        refresh();
    }
}

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
