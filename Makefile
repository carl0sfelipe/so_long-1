NAME = so_long

NAME_BONUS = so_long_bonus

MLX	= mandatory/mlx/libmlx.a

SRC = mandatory/ft_check_map.c\
	mandatory/ft_create_map.c\
	mandatory/ft_moving.c\
	mandatory/ft_read_map.c\
	mandatory/so_long.c\
	gnl/get_next_line_utils.c\
	gnl/get_next_line.c\

SRC_BONUS = gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		bonus/ft_check_map_bonus.c\
		bonus/ft_create_map_bonus.c\
		bonus/ft_enemy.c\
		bonus/ft_graphics_bonus.c\
		bonus/ft_moving_bonus.c\
		bonus/ft_read_map_bonus.c\
		bonus/ft_strj.c\
		bonus/ft_utils_bonus.c\
		bonus/so_long_bonus.c\

HDRS = mandatory/so_long.h

PRINTF_PATH		=	./printf
PRINTF			=	$(PRINTF_PATH)/libftprintf.a

HDRS_BONUS = bonus/so_long_bonus.h

OBJ_BONUS = $(SRC_BONUS:.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./mandatory/mlx -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(PRINTF) $(OBJ) $(HDRS)
		$(CC) $(SRC) $(PRINTF) $(FLAGS) $(MLX_FLAGS) -o $(NAME)

$(PRINTF):
		make -C $(PRINTF_PATH) all
		
bonus: $(OBJ_BONUS) $(HDRS_BONUS)
		$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

clean:
		rm -f $(OBJ_BONUS)
		rm -f $(OBJ)
		rm -rf printf/obj

fclean: clean
		rm -f $(NAME_BONUS)
		rm -f $(NAME)
		rm -f $(PRINTF)

re:		fclean all

.PHONY: all clean fclean