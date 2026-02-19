##
## EPITECH PROJECT, 2026
## G-PSU-200-MPL-2-1-minishell1-6
## File description:
## Makefile for my
##

HEADER		=	my.h
INCLUDE		=	../../include
LIB			=	../

SRC			=	my_strcmp.c				\
				my_strdup.c				\
				my_strlen.c				\
				my_put_nbr.c			\
				my_str_to_word_array.c	\
				my_strncmp.c			\
				my_nbr_to_str.c			\
				my_getnbr.c				\

NAME		=	libmy.a

OBJ         =   $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(LIB)
	cp $(HEADER) $(INCLUDE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB)$(NAME)

re:	fclean all