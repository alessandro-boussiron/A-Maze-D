##
## EPITECH PROJECT, 2026
## G-CPE-110-MPL-1-1-secured-5
## File description:
## Makefile
##
CC			=	epiclang

LIB			=	../

SRC			=	linked_list/linked_list_clear.c	\
				linked_list/linked_list_create.c	\
				linked_list/linked_list_destroy.c	\
				linked_list/linked_list_search.c	\
				linked_list/linked_list_apply.c	\
				linked_list/linked_list_dump.c	\
				linked_list/linked_list_set_dstr.c	\
				node/node_create.c	\
				node/node_destroy.c	\
				node/add_node.c	\
				node/get_node.c	\
				node/remove_node.c

NAME		=	ll.a

HEADER		=	linked_list.h

OBJ         =   $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIB)$(NAME)

re:	fclean all