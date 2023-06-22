/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/22 21:07:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void raycast_horizonal(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitHorizontal)
{
	int		horizontal_hit;//Dice si hay una colision horizontal
	float	y_intercept;
	float	x_intercept;
	t_coord step;

	horizontal_hit = 0;
	y_intercept = floor(player->square->p_center->y / map->lim) * map->lim;
	if(ray->down == 1)
		y_intercept += map->lim;
		
	x_intercept = player->square->p_center->x;
	x_intercept += (y_intercept - player->square->p_center->y) / tan(ray->rads_angle);

	step.y = map->lim;
	step.x = map->lim / (float)tan(ray->rads_angle);

	wallHitHorizontal->x = x_intercept;
	wallHitHorizontal->y = y_intercept;
	
	if(ray->down == 0)
		step.y = -step.y;
	if((ray->left == 1 && step.x > 0) || (ray->left == 0 && step.x < 0))
		step.x = -step.x;	
		
	//if(ray->down == 0)
		//nextHorizontal.y--;
	while(horizontal_hit == 0
		&&wallHitHorizontal->x < (float) map->len_x * map->width
		&&wallHitHorizontal->x > 1.0
		&&wallHitHorizontal->y > 1.0
		&&wallHitHorizontal->y < (float) map->len_y * map->height )
	{
		int box_x = (int)wallHitHorizontal->x / (int)map->lim;
		int box_y = (int)wallHitHorizontal->y / (int)map->lim;
		int box_x1 = ((int)wallHitHorizontal->x ) / (int)map->lim;
		int box_y1 = ((int)wallHitHorizontal->y - 1) / (int)map->lim;
		//Obtenemos casilla redondeada hacia abajo
		printf("vez\n");
		if((map->tour[box_y][box_x] == '1') || (ray->down == 0 && map->tour[box_y1][box_x1] == '1'))
		{
			printf("Entra_h\n");
			horizontal_hit = 1;
		}
		else
		{
			wallHitHorizontal->x += step.x;
			wallHitHorizontal->y += step.y;
		}	 
	}
}