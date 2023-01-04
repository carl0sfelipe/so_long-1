/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   so_long_utils2.c								   :+:	  :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: csiqueir <csiqueir@student.42.fr>	  +#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2022/12/29 21:32:45 by csiqueir		#+#  #+#		  */
/*   Updated: 2022/12/29 22:11:54 by csiqueir		 ###   ########.fr	   */
/*									  */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(char **map, int hight, int lenght,
	struct s_position *player_pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < hight)
	{
		j = 0;
		while (j < lenght)
		{
			if (map[i][j] == 'P')
			{
				break ;
			}
			j++;
		}
		if (map[i][j] == 'P')
		{
			break ;
		}
		i++;
	}
	player_pos->x = i;
	player_pos->y = j;
}

void	mark_accessible(int i, int j, char **map)
{
	if (map[i][j] && (map[i][j] == '0'
		|| map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E'))
	{
		map[i][j] = 'A';
		mark_accessible(i + 1, j, map);
		mark_accessible(i - 1, j, map);
		mark_accessible(i, j + 1, map);
		mark_accessible(i, j - 1, map);
	}
	else
		return ;
}
