##
## EPITECH PROJECT, 2024
## B-CPE-200-MPL-2-1-corewar-swann.peri-lunal
## File description:
## Makefile
##

SRCS	=	./srcs/my_strlen.c	\
		./srcs/my_putstr.c	\
		./srcs/my_strcmp.c	\
		./srcs/base_converter.c	\
		./srcs/add_char_pos.c	\
		./srcs/my_getnbr.c	\
		./srcs/my_strdup.c	\
		./srcs/my_strcpy_ncpy.c	\
		./srcs/my_putchar.c	\
		./srcs/my_putnbr.c	\
		./srcs/my_getlongnbr.c \
		./srcs/my_strcat.c \
		./srcs/my_strstr.c \
		./srcs/my_strspn.c \
		./srcs/my_strncat.c \
		./srcs/my_strchr.c \
		./srcs/my_str_isupper.c \
		./srcs/my_str_islower.c \
		./srcs/my_str_isnum.c \
		./srcs/my_str_isalpha.c \
		./srcs/my_str_isprintable.c \
		./srcs/my_memcpy.c \

CFLAGS	=	-I./includes/ -Wall -Wextra

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy.a

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)
