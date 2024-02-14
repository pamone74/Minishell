NAME = minishell
CC	 = cc
FLAG = -Wall -Wextra -Werror

SRC = linked.c minishell.c string_utils.c command_1.c
OBJ_SRC = $(SRC.c=.o)

all: $(NAME)
$(NAME) : $(OBJ_SRC)
	$(CC) $(FLAG) $(SRC) -o $(NAME) -lreadline
%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@
clean:
	rm -rf $(OBJ_SRC)
fclean:
	rm -rf $(NAME)
re: clean fclean all