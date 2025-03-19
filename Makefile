##
## EPITECH PROJECT, 2022
## make
## File description:
## makefile
##

CC	= gcc

SRC	= my_strcat.c	\
	  main.c	\
	  my_setenv.c	\
	  my_putstr.c	\
	  my_getenv.c	\
	  separator.c	\
	  shell.c	\
	  str_word_array2.c	\
	  segfault.c

OBJ	= $(SRC:.c=.o)

NAME	= mysh

all	: $(NAME)

$(NAME): $(SRC)
	gcc -o $(NAME) $(SRC) -g3

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
