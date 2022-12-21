
#include "so_long_bonus.h"

static int	int_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*convert(char *res, int n, int len_n, int minus)
{
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	res[len_n] = '\0';
	while (n != 0)
	{
		res[len_n - 1] = n % 10 * minus + 48;
		n = n / 10;
		len_n--;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		minus;
	char	*res;
	int		len_n;

	minus = 1;
	len_n = int_len(n);
	if (n < 0)
	{
		minus = -minus;
		len_n++;
	}
	res = (char *)malloc(sizeof(char) * (len_n + 1));
	if (!res)
		return (NULL);
	res = convert(res, n, len_n, minus);
	return (res);
}

void	free_map(t_init_map *data)
{
	int	i;

	i = 0;
	while (i < data->hight)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->graph);
}
