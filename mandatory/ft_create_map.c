/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_create_map.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: csiqueir <csiqueir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/24 16:21:19 by csiqueir		  #+#	#+#			 */
/*   Updated: 2022/12/28 23:31:38 by csiqueir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_init_map *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

void	put_player_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->player, (*j) * 40, (*i) * 40);
	data->y = *i;
	data->x = *j;
}

void	put_wall_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->wall, (*j) * 40, (*i) * 40);
}

void	put_empty_img(t_init_map *data, int *j, int *i)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->graph->empty, (*j) * 40, (*i) * 40);
}

void	ft_create_map(t_init_map *data)
{
	int		i;
	int		j;
	void	(*func_map[128])(t_init_map*, int*, int*);

	func_map['1'] = put_wall_img;
	func_map['0'] = put_empty_img;
	func_map['P'] = put_player_img;
	func_map['E'] = put_exit_img;
	func_map['C'] = put_collect_img;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			func_map[(int)data->map[i][j]](data, &j, &i);
			j++;
		}
		j = 0;
		i++;
	}
}
