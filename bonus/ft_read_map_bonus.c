
#include "so_long_bonus.h"

int	ft_exit(t_init_map *data)
{
	exit(EXIT_SUCCESS);
}

void	ft_map_hight(t_init_map *data)
{
	char		*line;
	int			fd;

	fd = open(data->fn, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("File not read\n");
		exit (EXIT_FAILURE);
	}
	while (line[data->lenght] != '\0')
		data->lenght++;
	while (line)
	{
		data->hight++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
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
	i = 0;
	while (line)
	{
		if (ft_strlen(line) != data->lenght)
		{
			printf("Error.Map not valide");
			exit(EXIT_FAILURE);
		}
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	free(line);
	line = NULL;
	close(fd);
}
