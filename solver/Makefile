##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

CFLAGS	=	-Wall -Wextra -Werror -W -g

CPPFLAGS	=	-I./include/

LDLIBS	=	-lcriterion

LD		= gcc

NAME	=	solver

MAIN	=	src/main.c

SRC	=	src/fill_arr.c	\
		src/solver.c	\
		src/get_next_line.c

TESTSRC	=	tests/test_ls.c

OBJ	=	$(SRC:.c=.o) $(MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(LD) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno
	rm -f vgcore.*

fclean:		clean
	rm -f $(NAME)

re:	fclean all

tests_run: CFLAGS += --coverage
tests_run: LDLIBS += -lcriterion
tests_run:
	gcc -o tests_run $(SRC) $(TESTSRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	./tests_run

debug:
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) $(LDFLAGS)

.PHONY: all clean fclean re tests_run