/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:13:56 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/29 21:53:19 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_exit_img(t_init_map *data, int *j, int *i)
{
mlx_put_image_to_window(data->mlx, data->win, data->graph->exit, *j * 40, *i * 40);
}

void put_collect_img(t_init_map *data, int *j, int *i)
{
mlx_put_image_to_window(data->mlx, data->win, data->graph->collect, *j * 40, *i * 40);
}

void ft_process_char(t_init_map *data, int *ex, char c)
{
    if (c == 'P')
        data->player += 1;
    else if (c == 'E')
        (*ex)++;
    else if (c == 'C')
        data->count += 1;
}


void	ft_game_result(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}

void check_for_errors(char **map, int hight, int lenght)
{
    int m;
    m = 0;
    while (m < hight) {
        int l;
        l = 0;
        while (l < lenght) {
            if ('C' == map[m][l] || 'E' == map[m][l]) {
                ft_printf("Error.\nCheck path");
                exit(EXIT_FAILURE);
            }
            l++;
        }
        m++;
    }
}