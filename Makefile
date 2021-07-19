##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

GENDIR	=	./generator
SOLVDIR	=	./solver

NAME	=	dantestar

all: $(NAME)

$(NAME):
	@make -C $(GENDIR)
	@make -C $(SOLVDIR)

clean:
	@make -C $(GENDIR)	clean
	@make -C $(SOLVDIR) clean

fclean:
	@make -C $(GENDIR)	fclean
	@make -C $(SOLVDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
