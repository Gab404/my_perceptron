SRC =   ./src/*.c

OBJ    =    $(SRC:.c=.o)

NAME   =    my_perceptron

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-I./includes

all:    $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
	fclean
	re