/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:22:41 by csiqueir          #+#    #+#             */
/*   Updated: 2023/01/02 21:51:56 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WALL "./pictures/wall.xpm"
# define EMPTY "./pictures/empty.xpm"
# define PLAYER "./pictures/player.xpm"
# define EXIT "./pictures/exit.xpm"
# define COLLECT "./pictures/collect.xpm"
# define WIN "./pictures/winner.xpm"

# if defined(__linux__)
#  define ESC 27
#  define W 119
#  define A 97
#  define S 115
#  define D 100
# elif defined(__APPLE__) && defined(__MACH__)
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../mlx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"

typedef struct s_graph
{
	void	*wall;
	void	*empty;
	void	*collect;
	void	*exit;
	void	*player;
	void	*winner;
}	t_graph;

typedef struct s_init_map
{
	int		hight;
	int		lenght;
	int		x;
	int		y;
	int		player;
	int		escape;
	int		count;
	int		step;
	char	**map;
	char	**cpymap;
	void	*wall;
	void	*mlx;
	void	*win;
	char	*fn;
	t_graph	*graph;

}	t_init_map;

struct position {
    int x;
    int y;
};

struct position_queue {
    int head;
    int tail;
    struct position *queue;
};

struct position_queue pq;



void	ft_read_map(t_init_map *data);
void	ft_map_hight(t_init_map *data);
void	ft_map_data(t_init_map *data, char *name);
void	ft_parse_map(t_init_map *render);
int		ft_frame(t_init_map *data);
void	ft_create_map(t_init_map *data);
int		ft_exit(t_init_map *data);
int		press_key(int keycode, t_init_map *data);

void	ft_char_set(t_init_map *data);
void	ft_check_char(t_init_map *data);
void	ft_check_format(t_init_map *data);
void	ft_check_wall(t_init_map *data);
void	ft_game_result(t_init_map *data);
void	ft_check_path(char **map, int hight, int lenght);
void	put_exit_img(t_init_map *data, int *j, int *i);
void	put_collect_img(t_init_map *data, int *j, int *i);
void	check_for_errors(char **map, int hight, int lenght);
void ft_process_char(t_init_map *data, int *ex, char c);
void	ft_game_result(t_init_map *data);
void find_player_position(char **map, int hight, int lenght, struct position *player_pos);
void mark_visited(char **map, int i, int j);
void initialize_directions(int **dx, int **dy);
void initialize_position_queue(struct position_queue *pq, int hight, int lenght);
void check_adjacent_positions(char **map, int integers[], int *dx, int *dy);
void ft_check_path(char **map, int hight, int lenght);
void free_position_queue(struct position_queue *pq);
void free_directions(int *dx, int *dy);




#endif
