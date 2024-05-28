##
## EPITECH PROJECT, 2024
## B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
## File description:
## Makefile
##

SRCS	=	./srcs/main.c	\
		./srcs/usages_error_func.c	\
		./srcs/arguments/args_manager.c	\
		./srcs/arguments/dump_arg.c	\
		./srcs/arguments/load_address_arg.c	\
		./srcs/arguments/prog_number_arg.c	\
		./srcs/parser/file_checker.c	\
		./srcs/parser/parser_header.c	\
		./srcs/parser/parser_body.c	\
		./srcs/cycle_loop.c	\
		./srcs/end_print.c	\
		./srcs/program_managers/destroy_n_add.c	\
		./srcs/program_managers/sort_progs.c	\
		./srcs/program_managers/delete_n_is_valid.c	\
		./srcs/program_managers/place_n_check_progs.c	\
		./srcs/commands/executor.c	\
		./srcs/commands/get_f_n_pc_manip.c	\
		./srcs/commands/checker.c	\
		./srcs/commands/bytes_manip.c	\
		./srcs/instructions/live.c	\
		./srcs/instructions/and.c	\
		./srcs/instructions/sti.c	\
		./srcs/instructions/zjmp.c	\
		./srcs/commands/write_pc.c	\
		./srcs/instructions/or.c	\
		./srcs/instructions/aff.c	\
		./srcs/instructions/fork.c	\
		./srcs/instructions/lfork.c	\
		./srcs/instructions/xor.c \
		./srcs/instructions/ld.c	\
		./srcs/instructions/st.c	\
		./srcs/instructions/ldi.c	\
		./srcs/instructions/lldi.c	\
		./srcs/instructions/add.c	\
		./srcs/instructions/sub.c	\
		./srcs/instructions/lld.c	\
		./srcs/program_managers/verify_size.c	\
		./srcs/op.c	\
		./srcs/my_op.c	\
		./srcs/parser/file_checker_bis.c	\
		./srcs/program_managers/place_n_check_progs_bis.c	\
		./srcs/error_print.c	\

OBJS	=	$(SRCS:.c=.o)

NAME	=	corewar

OPTI	=	-O3

NATIVE	=	-march=native

LINK_TIME_OPTI	=	-flto

CFLAGS	=	-I./includes/ -I../lib/includes/ -L../lib/ -lmy

STRICT =	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(OPTI) $(NATIVE) $(LINK_TIME_OPTI)
	@cp $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)
