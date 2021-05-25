##
## EPITECH PROJECT, 2021
## B-CPE-110-REN-1-1-BSQ-lucas.colleu
## File description:
## Makefile
##

SRC	=	my_put_nbr.c			\
		my_putchar.c			\
		my_getnbr.c			\
		my_strlen.c			\
		my_putstr.c			\
		my_find_char.c			\


CFLAGS	=	-I. -Wall -Wextra -Werror

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o
	mv $(NAME) ../
	mkdir -p ../../include
	cp my.h ../../include

clean:
	rm -f *.o

fclean:
	rm -f *.o


re:	fclean all
