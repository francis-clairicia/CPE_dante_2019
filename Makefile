##
## EPITECH PROJECT, 2019
## CPE_dante_2019
## File description:
## Makefile
##

all:
	make -C solver/
	make -C generator/

clean:
	make clean -C solver/
	make clean -C generator/

fclean:
	make fclean -C solver/
	make fclean -C generator/

re:	fclean all

tests_run:
	make tests_run -C solver/
	make tests_run -C generator/

.PHONY: all clean fclean re tests_run
