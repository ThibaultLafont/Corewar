/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
** File description:
** display_arena.c
*/

#include "corewar.h"

terminal_t *get_tty_size(void)
{
    terminal_t *term = malloc(sizeof(terminal_t));
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, y, x);
    term->x = x;
    term->y = y;
    return term;
}

void set_color(char display_char)
{
    switch (display_char) {
        case '1':
            attron(COLOR_PAIR(1));
            break;
        case '2':
            attron(COLOR_PAIR(2));
            break;
        case '3':
            attron(COLOR_PAIR(3));
            break;
        case '4':
            attron(COLOR_PAIR(4));
            break;
        default:
            break;
    }
}

void unset_color(char display_char)
{
    switch (display_char) {
        case '1':
            attroff(COLOR_PAIR(1));
            break;
        case '2':
            attroff(COLOR_PAIR(2));
            break;
        case '3':
            attroff(COLOR_PAIR(3));
            break;
        case '4':
            attroff(COLOR_PAIR(4));
            break;
        default:
            break;
    }
}

void draw_arena_box(int start_y, int start_x, int width)
{
    int height = MEM_SIZE / width;

    height = height + 3;
    for (int i = 0; i < width; i++) {
        mvaddch(start_y, start_x + i, ACS_HLINE);
    }
    for (int i = 0; i < width; i++) {
        mvaddch(start_y + height, start_x + i, ACS_HLINE);
    }
    for (int i = 0; i < height; i++) {
        mvaddch(start_y + i, start_x, ACS_VLINE);
    }
    for (int i = 0; i < height; i++) {
        mvaddch(start_y + i, start_x + width, ACS_VLINE);
    }
    mvaddch(start_y, start_x, ACS_ULCORNER);
    mvaddch(start_y, start_x + width, ACS_URCORNER);
    mvaddch(start_y + height, start_x, ACS_LLCORNER);
    mvaddch(start_y + height, start_x + width, ACS_LRCORNER);
}

static void print_base_display(int *arena, corewar_t *global)
{
    nodelay(stdscr, TRUE);
    clear();
    for (int i = 0; i < MEM_SIZE; i++) {
        if (arena[i] == 0 && global->display[i] == '5')
            global->display[i] = '0';
    }
}

static void print_info(int start_y, int start_x, corewar_t *global)
{
    mvprintw(start_y, start_x, "Cycle : %ld", global->cycle);
    mvprintw(start_y, start_x + 50,
    "Cycle to die : %d", global->cycles_to_die);
    mvprintw(start_y++, start_x + 25, "Nbr cycle dump : %ld",
    global->nbr_cycle_dump);
    mvprintw(start_y++, start_x, "Number of progs : %d",
    get_all_progs_sizes(global));
    mvprintw(start_y++, start_x, "Live calls : %d", global->live_calls);
    mvprintw(start_y, start_x, "Last live id : %d", global->last_live_id);
    mvprintw(start_y++, start_x + 25, "Last alive : %s", global->last_alive);
    usleep(500);
}

void display_arena(int *arena, corewar_t *global)
{
    terminal_t *term = get_tty_size();
    int start_y = term->y / 2 - MEM_SIZE / (2 * WIDTH) - 3;
    int start_x = term->x / 2 - WIDTH / 2;
    int info_start_x = 0;

    print_base_display(arena, global);
    draw_arena_box(start_y - 1, start_x - 1, WIDTH + 1);
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % WIDTH == 0) {
            mvprintw(start_y++, start_x, "\n");
            start_x = term->x / 2 - WIDTH / 2;
        }
        set_color(global->display[i]);
        mvprintw(start_y, start_x++, "%c", global->display[i]);
        unset_color(global->display[i]);
        if (i % WIDTH == WIDTH - 1)
            start_x = term->x / 2 + WIDTH / 2;
    }
    info_start_x = term->x / 2 - WIDTH / 2;
    print_info(start_y + 2, info_start_x, global);
}
