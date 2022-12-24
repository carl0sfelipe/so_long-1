/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:23:05 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/24 16:23:09 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_hight(t_init_map *data)
{
	char		*line;
	int			fd;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("File not read\n");
		exit (EXIT_FAILURE);
	}
	while (line[data->lenght] != '\0')
		data->lenght++;
	while (line)
	{
		if ((int)ft_strlen(line) != data->lenght)
		{
			ft_printf("Error.Map not valide");
			exit(EXIT_FAILURE);
		}
		data->hight++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_read_map(t_init_map *data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	data->map = (char **)malloc(sizeof(char *) * (data->hight + 1));
	data->cpymap = (char **)malloc(sizeof(char *) * (data->hight + 1));
	i = 0;
	while (line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	line = NULL;
	close(fd);
}
