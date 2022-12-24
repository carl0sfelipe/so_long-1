/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:22:13 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 16:22:18 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_init_map *data)
{
	if (data->map[data->y - 1][data->x] != '1')
	{
		if (data->map[data->y - 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y - 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		else if (data->map[data->y - 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->y--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_s(t_init_map *data)
{
	if (data->map[data->y + 1][data->x] != '1')
	{
		if (data->map[data->y + 1][data->x] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
			data->count--;
		}
		else if (data->map[data->y + 1][data->x] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		else if (data->map[data->y + 1][data->x] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->y++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_a(t_init_map *data)
{
	if (data->map[data->y][data->x - 1] != '1')
	{
		if (data->map[data->y][data->x - 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x - 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		else if (data->map[data->y][data->x - 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->x--;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

void	move_d(t_init_map *data)
{
	if (data->map[data->y][data->x + 1] != '1')
	{
		if (data->map[data->y][data->x + 1] == 'C')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
			data->count--;
		}
		else if (data->map[data->y][data->x + 1] == '0')
		{
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		else if (data->map[data->y][data->x + 1] == 'E'
			&& data->count == 0)
			data->escape = 1;
		data->x++;
		data->step++;
		ft_printf("Steps: %d\n", data->step);
	}
}

int	press_key(int keycode, t_init_map *data)
{
	if (keycode == ESC)
		ft_exit(data);
	else if (keycode == W)
		move_w(data);
	else if (keycode == A)
		move_a(data);
	else if (keycode == S)
		move_s(data);
	else if (keycode == D)
		move_d(data);
	return (0);
}
