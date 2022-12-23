
#include "so_long.h"

void ft_is_accessible(int i,int j,char ** mapa)
{
		if(mapa[i-1][j] != '1' && mapa[i-1][j] != 'E')
		{
			mapa[i-1][j] = 'P';
			//ft_is_accessible(i-1,j,map);
		}
		if(mapa[i+1][j] != '1' && mapa[i+1][j] != 'E')
		{
			mapa[i+1][j] = 'P';
			//ft_is_accessible(i+1,j,map);

		}
		if(mapa[i][j+1] != '1' && mapa[i][j+1] != 'E')
		{
			mapa[i][j+1] = 'P';
			//	ft_is_accessible(i,j+1,map);
		}
		if(mapa[i][j-1] != '1' && mapa[i][j-1] != 'E')
		{
			mapa[i][j-1] = 'P';
			//ft_is_accessible(i,j-1,map);
		}
}

void ft_check_path(t_init_map *data)
{
	int i;
	int j;

	i = 0;
	j = 0;

		while (data->map[i][j++] != 'P')
		{
			if(data->map[i][j]  == '\0')
			{
				if(i == data->hight)
					break;
				i++;
				j = 0;
			}
		}
data->cpymap = data->map;
ft_is_accessible(i,j,data->cpymap);


 	printf("i&j%s", data->cpymap[0]);
	printf("i&j%s", data->cpymap[1]);
	printf("i&j%s", data->cpymap[2]);
	printf("i&j%s", data->cpymap[3]);
	printf("i&j%s", data->cpymap[4]);
	printf("i&j%s", data->cpymap[5]);

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
		printf("Error.\nCheck walls");
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
		printf("Error.\nCheck file extansion");
		exit(EXIT_FAILURE);
	}
	i = len - 3;
	while (data->fn[i] != '\0' && ber[j] != '\0')
	{
		if (data->fn[i] != ber[j])
		{
			printf("Error.\nCheck file extansion");
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
				printf("Error.\nInvalid char at map");
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
		printf("Error.\n Map invalid"), exit(EXIT_FAILURE);
}

void	ft_game_result(t_init_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->graph->winner,
		data->lenght * 40 / 2.4, data->hight * 40 / 4);
}
