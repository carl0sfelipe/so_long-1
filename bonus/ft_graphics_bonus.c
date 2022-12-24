/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 18:09:47 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 18:09:49 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_steps(t_init_map *data)
{
	char	*mov;
	char	*moves;

	moves = ft_itoa(data->step);
	mov = ft_str_join("Step: ", moves);
	mlx_string_put(data->mlx, data->win, 2 * 40 + 1,
		0, 0x00FF0000, mov);
	free(mov);
	free(moves);
}

void	ft_lose(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->loser,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}

void	ft_win(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}
