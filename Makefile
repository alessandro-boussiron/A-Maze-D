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
	CFLAGS		=	-Wall -Wextra $(INCLUDE)
endif

ifdef DEBUG
	CFLAGS		+=	-g3

endif

INCLUDE		=	-I./include/

LIB	=	./lib/libmy.a	\
		./lib/ll.a

SRCF		=	src/

SRC			=	$(SRCF)init_structs.c	\
				$(SRCF)error_returns.c	\
				$(SRCF)parser_checks.c	\
				$(SRCF)parser.c	\

OBJ			=	$(SRC:.c=.o)

NAME		=	./amazed

MAIN		=	$(SRCF)main.c		\

TEST_FILES	=	tests/test_amazed.c		\

TEST_BIN	=	./unit_tests
TEST_FLAGS	=	--coverage -lcriterion

all:		$(NAME)

$(NAME): $(OBJ)
	make -f Makefile -C ./lib/my/ re
	make -f Makefile -C ./lib/linked_list/ re
	$(CC) $(SRC) $(MAIN) $(LIB) $(CFLAGS) -o $(NAME)

%o:			%.c
	$(CC) $(LIB) -o $< -c $@

clean:
	make -f Makefile -C ./lib/my/ clean
	make -f Makefile -C ./lib/linked_list/ clean
	$(RM) $(OBJ)

fclean:		clean
	make -f Makefile -C ./lib/my/ fclean
	make -f Makefile -C ./lib/linked_list/ fclean
	$(RM) $(NAME)

re:			fclean all

unit_tests:
	make -f Makefile -C ./lib/my/ re
	make -f Makefile -C ./lib/linked_list/ re
	clang $(TEST_FILES) $(SRC) $(INCLUDE) $(LIB) $(TEST_FLAGS) -o $(TEST_BIN)

tests_run:	unit_tests
	$(TEST_BIN)

tests_clean: 
	make -f Makefile -C ./lib/my/ fclean
	make -f Makefile -C ./lib/linked_list/ fclean
	rm -f ./unit_tests*

tests_re: tests_clean tests_run
