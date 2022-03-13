NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -g

HEADER = so_long.h

SRC =	so_long.c \
		check1.c \
		check2.c \
		keys.c \
		finish.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJ = $(SRC:c=o)

LIBFT = -L libft/ -lft
MLX = -L mlx

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C mlx
	make -C libft
	CC $(CFLAGS) $(MLX_FLAGS) -Imlx $(SRC) $(LIBFT) -I. -o $(NAME)

clean:
	make clean -C mlx
	make clean -C libft
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re