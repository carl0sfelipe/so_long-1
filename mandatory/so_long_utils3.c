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
	initialize_position_queue(&pq, integers[0], integers[1]);
	pq.queue[pq.tail] = (struct position){integers[2], integers[3]};
	pq.tail++;
	while (pq.head < pq.tail)
	{
		v.p = pq.queue[pq.head];
		pq.head++;
		v.k = 0;
		while (v.k < 4)
		{
			v.x = v.p.x + dx[v.k];
			v.y = v.p.y + dy[v.k];
			if (v.x >= 0 && v.x < integers[0] && v.y >= 0 && v.y < integers[1]
				&& map[v.x][v.y] != '1' && map[v.x][v.y] != 'V')
			{
				map[v.x][v.y] = 'V';
				pq.queue[pq.tail] = (struct position){v.x, v.y};
				pq.tail++;
			}
			v.k++;
		}
	}
}
