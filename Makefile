NAME = fractol
HEADER = fractal.h
LIBFT = libft
OS = $(shell uname)

SRC = main.c actions.c hooks.c help.c utils.c \
	  mandelbrot.c julia.c burningship.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f

ifeq ($(OS), Linux)
	MLX = ./mlx/mlx_linux
	MLX_CMD = -L $(MLX) -l mlx -L/usr/lib -I $(MLX) -lXext -lX11 -lm -lz
else
	MLX = ./mlx/mlx_mac
	MLX_CMD = -L $(MLX) -l mlx -framework OpenGL -framework AppKit
endif

$(NAME): $(OBJ)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(MLX_CMD) -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
