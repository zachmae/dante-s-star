##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = gcc -o
CFLAGS	=	-Wextra -Wall
CPPFLAGS +=  -I./include
RM = rm -rf

IDIR	=	include

SDIR	=	sources

TDIR	=	tests

SRC		=	$(SDIR)/solver.c	\
			$(SDIR)/readfile.c	\
			$(SDIR)/astar.c	\
			$(SDIR)/my_str_to_word_array.c	\
			$(SDIR)/list_handling.c	\
			$(SDIR)/check_node_status.c	\

MAIN	=	$(SDIR)/main.c

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)

NAME	=	solver

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
