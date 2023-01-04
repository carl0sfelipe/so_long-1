/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long_utils3.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: csiqueir <csiqueir@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/29 21:35:19 by csiqueir		  #+#	#+#			 */
/*   Updated: 2023/01/04 12:14:06 by csiqueir		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	initialize_position_queue(struct position_queue *pq
	, int hight, int lenght)
{
	pq->head = 0;
	pq->tail = 0;
	pq->queue = malloc(sizeof(struct position) * (hight * lenght));
}

void	check_adjacent_positions(char **map, int integers[], int *dx, int *dy)
{
	struct position	p;
	int				k;
	int				x;
	int				y;

	initialize_position_queue(&pq, integers[0], integers[1]);
	pq.queue[pq.tail] = (struct position){integers[2], integers[3]};
	pq.tail++;
	while (pq.head < pq.tail)
	{
		p = pq.queue[pq.head];
		pq.head++;
		k = 0;
		while (k < 4)
		{
			x = p.x + dx[k];
			y = p.y + dy[k];
			if (x >= 0 && x < integers[0] && y >= 0 && y < integers[1]
				&& map[x][y] != '1' && map[x][y] != 'V')
			{
				map[x][y] = 'V';
				pq.queue[pq.tail] = (struct position){x, y};
				pq.tail++;
			}
			k++;
		}
	}
}
