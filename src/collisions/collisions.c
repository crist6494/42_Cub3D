/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:59:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/17 14:13:26 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
 
int check_collision(t_map *map, t_player *player, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	printf("Avanza_x: %d\n", (int)advance_x);
	printf("Avanza_y: %d\n", (int)advance_y);
	printf("Ancho: %d\n", (int)map->width);
	printf("Alto: %d\n", (int)map->height);
	printf("P_center_x: %d\n", (int)player->square->p_center->x);
	printf("P_center_y: %d\n", (int)player->square->p_center->y);
	aux_x = player->square->p_center->x + advance_x;
	aux_y = player->square->p_center->y + advance_y + (player->tam / 2);
	printf("aux_x:%d\n", (int)aux_x);
	printf("aux_y:%d\n", (int)aux_y);
	printf("Pos:%d\n", (int)aux_x / map->width);
	printf("Pos:%d\n", (int)aux_y / map->height);
	//mlx_put_pixel(player->img, aux_x, aux_y, RED);
	if(map->tour[(unsigned int)aux_y / map->height][(unsigned int)aux_x / map->width] == '1')
	{
		printf("Entra\n");
		return (-1);
	}
	return (0);
}