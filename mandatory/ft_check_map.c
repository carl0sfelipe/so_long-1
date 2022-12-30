/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_check_map.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: csiqueir <csiqueir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/24 16:20:48 by csiqueir		  #+#	#+#			 */
/*   Updated: 2022/12/29 21:53:25 by csiqueir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(char **map, int hight, int lenght)
{	
	struct position	player_pos;
	int				*dx;
	int				*dy;

	dx = NULL;
	dy = NULL;
	initialize_directions(&dx, &dy);
	find_player_position(map, hight, lenght, &player_pos);
	mark_visited(map, player_pos.x, player_pos.y);
	check_adjacent_positions(map, hight, lenght,
		player_pos.x, player_pos.y, dx, dy);
	check_for_errors(map, hight, lenght);
	free_position_queue(&pq);
	free_directions(dx, dy);
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
			ft_process_char(data, &ex, data->map[j][i]);
			i++;
		}
		j++;
	}
	if (data->count == 0 || data->player == 0 || data->player > 1 || ex == 0)
	{
		ft_printf("Error.\n Map invalid");
		exit(EXIT_FAILURE);
	}
}
