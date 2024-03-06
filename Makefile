NAME=fdf

CC=gcc
FLAGS=-Wall -Wextra -Werror
EXTRAFLAGS=-pedantic -Weverything -Wno-missing-prototypes
LDFLAGS=-L/usr/X11/lib
MLXFLAGS=-lmlx -lXext -lX11
FLAGS=$(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

LIBFT=./libft.a
SRC_DIR=./src
INCLUDE_DIR=./include

SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(SRC:.c=.o)

COL_B=\033[1;34m
COL_G=\033[1;32m
COL_RES=\033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -I. -c $< -o $@

clean:
	-@rm $(OBJ)

fclean : clean
	@rm $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
