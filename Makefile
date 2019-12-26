##
## EPITECH PROJECT, 2017
## makefile
## File description:
## coding
##

SRC	=	my_str_to_word.c	\
		my_strdup.c		\
		check.c			\
		check_hit.c		\
		display.c		\
		pid.c			\
		load_map.c		\
		signal.c		\
		main.c			\
		atoi.c			\
		my_put_nbr.c		\
		my_funx.c

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

CFLAGS	=	-W -Wall -Werror -Wextra -ggdb -g3 -g

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		rm -f *~ *#

re:		fclean all
