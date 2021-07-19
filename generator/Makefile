##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = gcc -o
CFLAGS	=	-Werror -Wextra
CPPFLAGS +=  -I./include
RM = rm -rf

IDIR	=	include

SDIR	=	sources

TDIR	=	tests

SRC		=	$(SDIR)/generator.c	\
			$(SDIR)/perfect.c	\
			$(SDIR)/imperfect.c	\

MAIN	=	$(SDIR)/main.c

OBJ		=	$(SRC:.c=.o) \
			$(MAIN:.c=.o)

NAME	=	generator

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
