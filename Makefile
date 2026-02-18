##
## EPITECH PROJECT, 2026
## G-CPE-200-MPL-2-1-amazed-2
## File description:
## Makefile
##

ifdef CICD
	CC			=	gcc
	CFLAGS		=	-Wall -Wextra $(INCLUDE)
else
	CC			=	epiclang
	CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)
endif

INCLUDE		=	-I./include/

CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

LIB	=	./lib/libmy.a

SRCF		=	src/

SRC			=			\

OBJ			=	$(SRC:.c=.o)

NAME		=	./amazed

MAIN		=	$(SRCF)main.c		\

TEST_FILES	=	tests/test_amazed.c		\

TEST_BIN	=	./unit_tests
TEST_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME): $(OBJ)
	make -f Makefile -C ./lib/my/ all re
	$(CC) $(SRC) $(MAIN) $(LIB) $(CFLAGS) -o $(NAME)

%o:			%.c
	$(CC) $(LIB) -o $< -c $@

clean:
	make -f Makefile -C ./lib/my/ clean
	$(RM) $(OBJ)

fclean:		clean
	make -f Makefile -C ./lib/my/ fclean
	$(RM) $(NAME)

re:			fclean all

unit_tests:
	gcc $(TEST_FILES) $(SRC) $(INCLUDE) $(LIB) $(TEST_FLAGS) -o $(TEST_BIN)

tests_run:	unit_tests
	$(TEST_BIN)

tests_clean: 
	rm -f ./unit_tests*

tests_re: tests_clean tests_run
