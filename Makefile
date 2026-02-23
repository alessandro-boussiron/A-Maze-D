##
## EPITECH PROJECT, 2026
## G-CPE-200-MPL-2-1-amazed-2
## File description:
## Makefile
##

ifdef CICD
	CC			=	gcc
else
	CC			=	epiclang
endif

CFLAGS		=	-Wall -Wextra $(INCLUDE)

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
				$(SRCF)parser.c			\
				$(SRCF)link_two_rooms.c	\
				$(SRCF)set_weight.c
				$(SRCF)prints.c			\
				$(SRCF)set_weight.c

OBJ			=	$(SRC:.c=.o)

NAME		=	./amazed

MAIN		=	$(SRCF)main.c

TEST_FILES	=	tests/test_amazed.c

TEST_BIN	=	./unit_tests
TEST_FLAGS	=	--coverage -lcriterion

all:        $(NAME)

$(NAME): $(OBJ) $(MAIN) $(LIB)
	$(CC) $^ $(CFLAGS) -o $@

$(LIB):
	make -f Makefile -C ./lib/my/
	make -f Makefile -C ./lib/linked_list/

%o:            %.c
	$(CC) -c $< $(CFLAGS) -o $@
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

.PHONY: all clean fclean re unit_tests tests_run tests_clean tests_re $(LIB)
