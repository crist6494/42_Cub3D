/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/28 19:40:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	vertical_raycast_loop(t_map *map, t_coord *wall_hit_vertical, t_coord *step, t_ray *data);

void raycast_vertical(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitVertical)
{
	float	y_intercept;
	float	x_intercept;
	t_coord step;
	
	x_intercept = floor(player->square->p_center->x / map->lim) * map->lim;
	if(ray->left == 0)
		x_intercept += map->lim;
	y_intercept = player->square->p_center->y;
	y_intercept += ((x_intercept - player->square->p_center->x) * tan(ray->rads_angle));
	step.x = map->lim;
	step.y = map->lim * tan(ray->rads_angle);
	wallHitVertical->x = x_intercept;
	wallHitVertical->y = y_intercept;
	step.y = -step.y;
	if (ray->left == 1)
		step.x = -step.x;
	if (ray->left == 0)
		step.y = -step.y;
	vertical_raycast_loop(map, wallHitVertical, &step, ray);
}

static void	vertical_raycast_loop(t_map *map, t_coord *wallHitVertical, t_coord *step, t_ray *data)
{
	int	vertical_hit;

	vertical_hit = 0;
	while (vertical_hit == 0
		&& wallHitVertical->x < (float)(map->width)
		&& wallHitVertical->x > 1.0 && wallHitVertical->y > 1.0
		&& wallHitVertical->y < (float)(map->height))
	{
		if (map->tour[(int)wallHitVertical->y / (int)map->lim][(int)wallHitVertical->x / (int)map->lim] == '1'
			|| (data->left == 1 && map->tour[((int)wallHitVertical->y)
			/ (int)map->lim][(int)(wallHitVertical->x - 1)
			/ (int)map->lim] == '1'))
			vertical_hit = 1;
		else
		{
			wallHitVertical->x += step->x;
			wallHitVertical->y += step->y;
		}
	}
}

	/* printf("\n");
	printf("P_x: %f\n", player->square->p_center->x);
	printf("P_y: %f\n", player->square->p_center->y);
	printf("Tangente: %f\n", (float)tan(ray->rads_angle));
	printf("Diferencia: %f\n", (float)(x_intercept - player->square->p_center->x));
	printf("y_intercept: %f\n", y_intercept);
	printf("x_intercept: %f\n", x_intercept);
	printf("step_x: %f\n", step.x);
	printf("step_y: %f\n", step.y); */
