SRC =   ./src/getData.c \
        ./src/gradient.c \
        ./src/handleError.c \
        ./src/loadNetwork.c \
        ./src/main.c \
        ./src/mathFunction.c \
        ./src/network.c \
        ./src/saveWeights.c \
        ./src/train.c \

OBJ    =    $(SRC:.c=.o)

NAME   =    perceptron

CFLAGS += -Wall -Wextra

CPPFLAGS    +=  -I./includes

LIBS += -lm

all:    $(NAME)

$(NAME): $(OBJ)
    gcc -o $(NAME) $(OBJ) $(LIBS)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: clean
    fclean
    re