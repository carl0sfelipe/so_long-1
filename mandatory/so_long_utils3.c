/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:35:19 by csiqueir          #+#    #+#             */
/*   Updated: 2023/01/02 22:09:06 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


void initialize_position_queue(struct position_queue *pq, int hight, int lenght)
{
    pq->head = 0;
    pq->tail = 0;
    pq->queue = malloc(sizeof(struct position) * (hight * lenght));
}

void check_adjacent_positions(char **map, int integers[], int *dx, int *dy)
{
    // use integers in the function
    int hight = integers[0];
    int lenght = integers[1];
    int i = integers[2];
    int j = integers[3];

    initialize_position_queue(&pq, hight, lenght);

    // Add the starting position to the queue
    pq.queue[pq.tail] = (struct position) {i, j};
    pq.tail++;

    // Repeat until the queue is empty
    while (pq.head < pq.tail) {
        // Get the next position from the queue
        struct position p;
        p = pq.queue[pq.head];
        pq.head++;

        // Check the adjacent positions
        int k;
        k = 0;
        while (k < 4) {
            int x;
            x = p.x + dx[k];
            int y;
            y = p.y + dy[k];
            if (x >= 0 && x < hight && y >= 0 && y < lenght && map[x][y] != '1' && map[x][y] != 'V') {
                map[x][y] = 'V';
                pq.queue[pq.tail] = (struct position) {x, y};
                pq.tail++;
            }
            k++;
        }
    }
}
