##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

all:
	make -C solver/

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
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

.PHONY: all clean fclean re tests_run
