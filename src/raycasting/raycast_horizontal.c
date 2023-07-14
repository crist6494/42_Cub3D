/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 12:10:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	horizontal_raycast_loop(t_map *map, t_coord *wall_hit_horizontal,
				t_coord *step, t_ray *data);

void	raycast_horizonal(t_map *map, t_player *player, t_ray *ray,
		t_coord *wallHitHorizontal)
{
	float	y_intercept;
	float	x_intercept;
	t_coord	step;

	y_intercept = floor(player->square->p_center->y / map->lim) * map->lim;
	if (ray->down == 1)
		y_intercept += map->lim;
	x_intercept = player->square->p_center->x;
	x_intercept += (y_intercept - player->square->p_center->y)
		/ tan(ray->rads_angle);
	step.y = map->lim;
	step.x = map->lim / tan(ray->rads_angle);
	wallHitHorizontal->x = x_intercept;
	wallHitHorizontal->y = y_intercept;
	step.x = -step.x;
	if (ray->down == 0)
		step.y = -step.y;
	if (ray->down == 1)
		step.x = -step.x;
	horizontal_raycast_loop(map, wallHitHorizontal, &step, ray);
}

static void	horizontal_raycast_loop(t_map *map, t_coord *wallHitHorizontal,
		t_coord *step, t_ray *ray)
{
	int	horizontal_hit;

	horizontal_hit = 0;
	while (horizontal_hit == 0 && wallHitHorizontal->x < (float)(map->width)
		&& wallHitHorizontal->x > 1.0 && wallHitHorizontal->y > 1.0
		&& wallHitHorizontal->y < (float)(map->height))
	{
		if (map->tour[(int)wallHitHorizontal->y
			/ (int)map->lim][(int)wallHitHorizontal->x / (int)map->lim] == '1'
			|| (ray->down == 0 && map->tour[(int)(wallHitHorizontal->y - 1)
				/ (int)map->lim][((int)wallHitHorizontal->x)
				/ (int)map->lim] == '1'))
			horizontal_hit = 1;
		else
		{
			wallHitHorizontal->x += step->x;
			wallHitHorizontal->y += step->y;
		}
	}
}
