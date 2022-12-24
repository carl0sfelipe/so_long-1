
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *memory, char const *tmp)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!memory)
	{
		memory = (char *)malloc(1 * sizeof(char));
		memory[0] = '\0';
	}
	if (!memory || !tmp)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(memory) + ft_strlen(tmp)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (memory)
		while (memory[++i] != '\0')
			str[i] = memory[i];
	while (tmp[j] != '\0')
		str[i++] = tmp[j++];
	str[ft_strlen(memory) + ft_strlen(tmp)] = '\0';
	free(memory);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
