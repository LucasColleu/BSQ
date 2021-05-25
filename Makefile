##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## A Makefile, read by make command, execute all commands and rules in the Makefile
##


SRC =		main.c	\
			src/freebuffer.c	\
			src/check_error.c	\
			src/find_square.c 	\
			src/biggest_square.c	\
			src/bsq.c	\

NAME =	 bsq

CFLAGS = -I./include -Wall -Wextra -L./lib -lmy

all:
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(SRC) $(CFLAGS) -g

clean:
	rm -f $(NAME)



fclean: clean
	rm -f $(NAME)
	rm -f ./lib/my/*.o
	rm -f lib/my/libmy.a
	rm -f lib/libmy.a
	rm -f lib/my/*~
	rm -f include/*~
	rm -f *~
	rm -f src/*~

re:	fclean all
