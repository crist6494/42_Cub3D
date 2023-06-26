/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/26 18:08:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	horizontal_ray_cast_loop(t_map *map, t_coord *wall_hit_horizontal, t_coord *step, t_ray *data);

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
	
	step.x = -step.x;
	if (ray->down == 0)
		step.y = -step.y;
	if (ray->down == 1)
		step.x = -step.x;
		
	horizontal_ray_cast_loop(map, wallHitHorizontal, &step, ray);
}

void	horizontal_ray_cast_loop(t_map *map, t_coord *wall_hit_horizontal, t_coord *step, t_ray *data)
{
	int	horizontal_hit;

	horizontal_hit = 0;
	printf("%d\n", map->len_x);
	printf("%d\n", map->len_y);
	printf("%d\n", map->width);
	printf("%d\n", map->height);
	while (horizontal_hit == 0
		&& wall_hit_horizontal->x < (float)(map->width)
		&& wall_hit_horizontal->x > 1.0 && wall_hit_horizontal->y > 1.0
		&& wall_hit_horizontal->y < (float)(map->height))
	{
		if (map->tour[(int)wall_hit_horizontal->y / (int)map->lim][(int)wall_hit_horizontal->x / (int)map->lim] == '1' 
			|| (data->down == 0 && map->tour[(int)(wall_hit_horizontal->y - 1)/ (int)map->lim][((int)wall_hit_horizontal->x) / (int)map->lim] == '1'))
			horizontal_hit = 1;
		else
		{
			wall_hit_horizontal->x += step->x;
			wall_hit_horizontal->y += step->y;
		}
	}
}

/* 	printf("\n");
	printf("P_x: %f\n", player->square->p_center->x);
	printf("P_y: %f\n", player->square->p_center->y);
	printf("Tangente: %f\n", (float)tan(ray->rads_angle));
	printf("Diferencia: %f\n", (float)(y_intercept - player->square->p_center->y));
	printf("x_intercept: %f\n", x_intercept);
	printf("y_intercept: %f\n", y_intercept);
	printf("step_x: %f\n", step.x);
	printf("step_y: %f\n", step.y);
	printf("\n--------------------------------------\n"); */