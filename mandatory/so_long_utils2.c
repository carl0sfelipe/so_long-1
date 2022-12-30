/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csiqueir <csiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:32:45 by csiqueir          #+#    #+#             */
/*   Updated: 2022/12/29 21:52:51 by csiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_position_queue(struct position_queue *pq)
{
    free(pq->queue);
}

void free_directions(int *dx, int *dy)
{
    free(dx);
    free(dy);
}


void find_player_position(char **map, int hight, int lenght, struct position *player_pos)
{
    int i;
    i = 0;
	        int j;
        j = 0;
    while (i < hight) {
        j = 0;
        while (j < lenght) {
            if (map[i][j] == 'P') {
                break;
            }
            j++;
        }
        if (map[i][j] == 'P') {
            break;
        }
        i++;
    }

    player_pos->x = i;
    player_pos->y = j;
}

void mark_visited(char **map, int i, int j)
{
    map[i][j] = 'V';
}

void initialize_directions(int **dx, int **dy)
{
    *dx = malloc(sizeof(int) * 4);
    (*dx)[0] = -1;
    (*dx)[1] = 1;
    (*dx)[2] = 0;
    (*dx)[3] = 0;

    *dy = malloc(sizeof(int) * 4);
    (*dy)[0] = 0;
    (*dy)[1] = 0;
    (*dy)[2] = -1;
    (*dy)[3] = 1;
}

