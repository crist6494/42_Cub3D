/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/22 20:39:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void raycast_vertical(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitVertical)
{
	int		vertical_hit;
	float	y_intercept;
	float	x_intercept;
	t_coord step;
	
	vertical_hit = 0;
	x_intercept = floor(player->square->p_center->x / map->lim) * map->lim;
	if(ray->left == 0)
		x_intercept += map->lim;
		
	y_intercept = player->square->p_center->y;
	y_intercept += ((x_intercept - player->square->p_center->x) * tan(ray->rads_angle));
	
	step.x = map->lim;
	step.y = map->lim * (float)tan(ray->rads_angle);

	wallHitVertical->x = x_intercept;
	wallHitVertical->y = y_intercept;

	if(ray->left == 1)
		step.x = -step.x;
	if((ray->down == 0 && step.y > 0) || (ray->down == 1 && step.y < 0))
		step.y = -step.y;

	//if(ray->left == 1)
		//nextVertical.x--;

	while(vertical_hit == 0
		&&wallHitVertical->x < (float) map->len_x * map->width
		&&wallHitVertical->x > 1.0
		&&wallHitVertical->y > 1.0
		&&wallHitVertical->y < (float) map->len_y * map->height)
	{
		int box_x;
		int box_y;
		int box_x1;
		int box_y1;

		box_x = (int)wallHitVertical->x / (int)map->lim;
		box_y = (int)wallHitVertical->y / (int)map->lim;
		box_x1 = ((int)wallHitVertical->x -1) / (int)map->lim;
		box_y1 = ((int)wallHitVertical->y) / (int)map->lim;
		if((map->tour[box_y][box_x] == '1') || (ray->left == 1 && map->tour[box_y1][box_x1]))
		{
			printf("Entra_v\n");
			vertical_hit = 1;
		}
		else
		{
			wallHitVertical->x += step.x;
			wallHitVertical->y += step.y;
		}	 
	}
}
