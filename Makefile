##
## EPITECH PROJECT, 2019
## CPE_dante_2019
## File description:
## Makefile
##

all:
	make -C solver/

clean:
	make clean -C solver/

fclean:
	make fclean -C solver/

re:	fclean all

tests_run:
	make tests_run -C solver/

.PHONY: all clean fclean re tests_run
