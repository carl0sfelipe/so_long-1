NAME = so_long

MLX	= mlx/libmlx.a

MLX_LINUX = minilibx-linux/libmlx.a



SRC = mandatory/ft_check_map.c\
	mandatory/ft_create_map.c\
	mandatory/ft_moving.c\
	mandatory/ft_read_map.c\
	mandatory/so_long.c\
	mandatory/so_long_utils.c\
	mandatory/so_long_utils2.c\
	gnl/get_next_line_utils.c\
	gnl/get_next_line.c\

HDRS = mandatory/so_long.h

PRINTF_PATH		=	./printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework Appkit

DETECTED_OS	= $(shell uname)

ifeq ($(DETECTED_OS), Linux)
$(NAME): $(OBJS) $(MLX_LINUX) $(LIBFT)
	make -C mlx-linux
	$(CC) $(OBJS) -Llibft -lft -L./mlx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@
elsepy

$(NAME): $(PRINTF) $(OBJ) $(HDRS)
		make -C mlx
		$(CC) $(SRC) $(PRINTF) $(FLAGS) $(MLX_FLAGS) -o $(NAME)
endif

$(NAME): $(PRINTF) $(OBJ) $(HDRS)
		make -C mlx
		$(CC) $(SRC) $(PRINTF) $(FLAGS) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

$(MLX_LINUX):
		make -C mlx-linux

$(PRINTF):
		make -C $(PRINTF_PATH) all

clean:
		rm -f $(OBJ)
		rm -rf printf/obj

fclean: clean
		rm -f $(NAME)
		rm -f $(PRINTF)
		rm -f mlx/libmlx.a
		make -C mlx clean

re:		fclean all

.PHONY: all clean fclean