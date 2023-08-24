/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/24 17:53:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	vertical_raycast_loop(t_map *map, t_coord *wall_hit_vertical,
				t_coord *step, t_ray *data);

//Fuction to get the coord of the hit vertcial
void	raycast_vertical(t_map *map, t_player *player, t_ray *ray,
		t_coord *wallHitVertical)
{
	float	y_intercept;
	float	x_intercept;
	t_coord	step;

	//Get the coord x of the triangle
	x_intercept = floor(player->square->p_center->x / map->lim) * map->lim;
	//If look left we add one for be good
	if (ray->left == 0)
		x_intercept += map->lim;
	//We know y0 so add the dy and we have y1
	y_intercept = player->square->p_center->y;
	// dy ==  tan = y / x  clear y //  y = x * tan(angle)
	y_intercept += ((x_intercept - player->square->p_center->x)
			* tan(ray->rads_angle));
	//Know have the first tile collision do the same to we find a wall
	//doing the same y = x * tan(angle) and x is the tile column
	step.x = map->lim;
	step.y = map->lim * tan(ray->rads_angle);
	wallHitVertical->x = x_intercept;
	wallHitVertical->y = y_intercept;
	//If we go left we change the sign
	if(ray->left == 1)
		step.x = -step.x;
	//Test if we go up and is positive we change the sign and in the other way
	if((ray->down == 0 && step.y > 0) || (ray->down == 1 && step.y < 0))
		step.y = -step.y;
	vertical_raycast_loop(map, wallHitVertical, &step, ray);
}

static void	vertical_raycast_loop(t_map *map, t_coord *wallHitVertical,
		t_coord *step, t_ray *data)
{
	int	vertical_hit;

	vertical_hit = 0;
	//Loop to finish when find a collision and not pass the limits
	while (vertical_hit == 0 && wallHitVertical->x < (float)(map->width)
		&& wallHitVertical->x > 1.0 && wallHitVertical->y > 1.0
		&& wallHitVertical->y < (float)(map->height))
	{
		//Know spliting the wall hit coord by the size of each tile know if the tile is a wall or not
		// The || condition is for check when go left it is necessary to subtract one box to be ok
		if (map->tour[(int)wallHitVertical->y
				/ (int)map->lim][(int)wallHitVertical->x
			/ (int)map->lim] == '1'
			|| (data->left == 1 && map->tour[((int)wallHitVertical->y)
				/ (int)map->lim][(int)(wallHitVertical->x - 1)
				/ (int)map->lim] == '1'))
			vertical_hit = 1;
		else
		{
			//Add the next step tile 
			wallHitVertical->x += step->x;
			wallHitVertical->y += step->y;
		}
	}
}
