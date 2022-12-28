/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:20:48 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/27 21:50:38 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void ft_is_accessible(int i, int j, char **mapa, int hight,int lenght)
{
    if (mapa == NULL || i < 0 || i >= hight || j < 0 || j >= lenght || (mapa[i][j] != 'A' && mapa[i][j] != 'P')) {
        return;
    }

    if (mapa[i-1][j] != '1' && mapa[i-1][j] != 'E')
    {
        mapa[i-1][j] = 'A';
        ft_is_accessible(i-1,j,mapa, hight, lenght);
    }
    if (mapa[i+1][j] != '1' && mapa[i+1][j] != 'E')
    {
        mapa[i+1][j] = 'A';
        ft_is_accessible(i+1,j,mapa, hight, lenght);
    }
    if (mapa[i][j+1] != '1' && mapa[i][j+1] != 'E')
    {
        mapa[i][j+1] = 'A';
        ft_is_accessible(i,j+1,mapa, hight, lenght);
    }
    if (mapa[i][j-1] != '1' && mapa[i][j-1] != 'E')
    {
        mapa[i][j-1] = 'A';
        ft_is_accessible(i,j-1,mapa, hight, lenght);
    }
}


int ft_check_path_recursive(char **map, int hight, int length, int row, int col)
{
    // Check if the position is valid and not a wall
    if (row < 0 || row >= hight || col < 0 || col >= length || map[row][col] == '1') {
        return 0;
    }

    // Check if the position is the end
    if (map[row][col] == 'E') {
        return 1;
    }

    // Mark the position as visited
    map[row][col] = 'V';

    // Check the adjacent positions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int direction = 0;
    while (direction < 4) {
        int new_row = row + dx[direction];
        int new_col = col + dy[direction];
        if (ft_check_path_recursive(map, hight, length, new_row, new_col)) {
            return 1;
        }
        direction++;
    }

    // If none of the adjacent positions leads to the end, return 0
    return 0;
}

*/

void ft_check_path(char **map, int hight, int lenght)
{/*
	int i;
	int j;

	i = 0;
	j = 0;

	    while (i < hight && map[i][j] != 'P') {
        // Move to the next column
        j++;
        if (j == lenght) {
            // If the end of the row is reached, move to the next row and reset the column
            i++;
            j = 0;
        }
    }
*/
//ft_check_path_recursive(map, hight, lenght, player_row, player_col);


	//ft_is_accessible(i,j,data->cpymap, data->hight, data->lenght);
	


    int i, j;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Find the starting position of the player
i = 0;
while (i < hight) {
  j = 0;
  while (j < lenght) {
    if (map[i][j] == 'P') {
      break;
    }
    j++;
  }
  if (map[i][j] == 'P') {
    break;
  }
  i++;
}


    // Create a queue to store the positions to visit
    struct position {
        int x;
        int y;
    };
    struct position queue[hight * lenght];
    int head = 0;
    int tail = 0;

    // Add the starting position to the queue
    queue[tail++] = (struct position) {i, j};

    // Mark the starting position as visited
    map[i][j] = 'V';

    // Repeat until the queue is empty
    while (head < tail) {
        // Get the next position from the queue
        struct position p = queue[head++];

        // Check the adjacent positions
int k = 0;
while (k < 4) {
  int x = p.x + dx[k];
  int y = p.y + dy[k];
  if (x >= 0 && x < hight && y >= 0 && y < lenght && map[x][y] != '1' && map[x][y] != 'V') {
    map[x][y] = 'V';
    queue[tail++] = (struct position) {x, y};
  }
  k++;
}

          /*  if (map[x][y] == 'E') {
                // If the position is the end, return true
					ft_printf("i&j%s\n", map[0]);
	ft_printf("i&j%s\n", map[1]);
	ft_printf("i&j%s\n", map[2]);
	ft_printf("i&j%s\n", map[3]);
	ft_printf("i&j%s\n", map[4]);
	ft_printf("i&j%s\n", map[5]);
                return 1;
				break;
            }*/
        
    }
int m = 0;
int l = 0;
while(m < hight)
{
	while(l < lenght)
	{
		//ft_printf("i&j%c\n", map[m][l]);
		if('C' == map[m][l] || 'E' == map[m][l])
		{
			ft_printf("Error.\nCheck path");
			exit(EXIT_FAILURE);
		}
		l++;
	}
	l = 0;
m++;
}


    // If the queue is empty and the end was not reached, return false



 


}


void	ft_check_wall(t_init_map *data)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->lenght - 1] != '1')
			err++;
		i++;
	}
	i = 0;
	while (i < data->lenght)
	{
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
	{
		ft_printf("Error.\nCheck walls");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_format(t_init_map *data)
{
	char	*ber;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	ber = "ber";
	len = ft_strlen(data->fn);
	if (len < 3)
	{
		ft_printf("Error.\nCheck file extansion");
		exit(EXIT_FAILURE);
	}
	i = len - 3;
	while (data->fn[i] != '\0' && ber[j] != '\0')
	{
		if (data->fn[i] != ber[j])
		{
			ft_printf("Error.\nCheck file extansion");
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
}

void	ft_check_char(t_init_map *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[j])
	{
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P' || data->map[j][i] == 'E'
				|| data->map[j][i] == '1' || data->map[j][i] == 'C'
				|| data->map[j][i] == '0')
				i++;
			else
			{
				ft_printf("Error.\nInvalid char at map");
				exit(EXIT_FAILURE);
			}
		}
		i = 0;
		j++;
	}
}

void	ft_char_set(t_init_map *data)
{
	int	i;
	int	j;
	int	ex;

	i = 0;
	j = 0;
	ex = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				data->player += 1;
			else if (data->map[j][i] == 'E')
				ex++;
			else if (data->map[j][i] == 'C')
				data->count += 1;
			i++;
		}
		j++;
	}
	if (data->count == 0 || data->player == 0
		|| ex == 0 || data->player > 1)
		ft_printf("Error.\n Map invalid"), exit(EXIT_FAILURE);
}

void	ft_game_result(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}
