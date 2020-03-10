##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC_NO_TEST			=	src/main.c

SRC_TEST			=	src/generator.c					\
						src/word_array.c				\
						src/int_array.c					\
						src/sidewinder/sidewinder.c		\
						src/sidewinder/generate_maze.c	\
						src/sidewinder/perfect_maze.c

SRC					=	$(SRC_NO_TEST) $(SRC_TEST)

CFLAGS				=	-Wall -Wextra

CPPFLAGS			=	-I./include/

OBJ					=	$(SRC:.c=.o)

NAME				=	generator

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LDLIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_TEST) tests/*.c $(CFLAGS) $(CPPFLAGS)
	./unit_tests
	$(RM) unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	CFLAGS += -g
debug:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all tests_run debug clean fclean re
