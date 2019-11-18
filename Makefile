##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c	\
		src/bsq.c	\
		src/square.c

OBJ =   $(SRC:.c=.o)

NAME    =   bsq

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

TEST	=	@gcc -o unit_tests src/bsq.c src/square.c tests/tests_bsq.c $(LDFLAGS) $(CFLAGS) --coverage -lcriterion

all:    $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
	$(TEST)

clean:
	@make clean -C lib/my/ --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/my/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean