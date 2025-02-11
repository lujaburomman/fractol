NAME = fractol
CC = cc
CFLAGS = -Werror -Wall -Wextra

LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

INCLUDES = -I$(LIBFT_DIR)/includes -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
CFLAGS += $(INCLUDES)

SRCS = main.c hook.c fractol.c initial_parse.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft mlx
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) -C $(LIBFT_DIR)

mlx:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft mlx