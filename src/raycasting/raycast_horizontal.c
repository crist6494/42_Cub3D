/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/09 22:54:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	horizontal_raycast_loop(t_map *map, t_coord *wall_hit_horizontal,
				t_coord *step, t_ray *data);

//Fuction to get the coord of the hit horizontal
void	raycast_horizonal(t_map *map, t_player *player, t_ray *ray,
		t_coord *wallHitHorizontal)
{
	float	y_intercept;
	float	x_intercept;
	t_coord	step;

	//Get the coord dy of the triangle
	y_intercept = floor(player->square->p_center->y / map->lim) * map->lim;
	//If look down we add one for be good
	if (ray->down == 1)
		y_intercept += map->lim;
	//Get the cooird x with the tan because Know y and the angle
	//We know x0 so add the dx and we have x1
	x_intercept = player->square->p_center->x;
	// dx == tan = y / x  clear x //  x = y / tan(angle)
	x_intercept += (y_intercept - player->square->p_center->y)
		/ tan(ray->rads_angle);
	//Know have the first tile collision do the same to we find a wall
	//doing the same x = y / tan(angle) and y is the tile row
	step.y = map->lim;
	step.x = map->lim / tan(ray->rads_angle);
	wallHitHorizontal->x = x_intercept;
	wallHitHorizontal->y = y_intercept;
	//If we go up we change the sign 
	if(ray->down == 0)
		step.y = -step.y;
	//Test if we go left and is positive we change the sign and in the other way
	if((ray->left == 1 && step.x > 0) || (ray->left == 0 && step.x < 0))
		step.x = -step.x;
	horizontal_raycast_loop(map, wallHitHorizontal, &step, ray);
}

static void	horizontal_raycast_loop(t_map *map, t_coord *wallHitHorizontal,
		t_coord *step, t_ray *ray)
{
	int	horizontal_hit;

	horizontal_hit = 0;
	//Loop to finish when find a collision and not pass the limits
	while (horizontal_hit == 0 && wallHitHorizontal->x < (float)(map->width)
		&& wallHitHorizontal->x > 1.0 && wallHitHorizontal->y > 1.0
		&& wallHitHorizontal->y < (float)(map->height))
	{
		//Know spliting the wall hit coord by the size of each tile know if the tile is a wall or not
		// The || condition is for check when go up it is necessary to subtract one box to be ok
		if (map->tour[(int)wallHitHorizontal->y
				/ (int)map->lim][(int)wallHitHorizontal->x
			/ (int)map->lim] == '1'
			|| (ray->down == 0 && map->tour[(int)(wallHitHorizontal->y - 1)
				/ (int)map->lim][((int)wallHitHorizontal->x)
				/ (int)map->lim] == '1'))
			horizontal_hit = 1;
		else
		{
			//Add the next step tile 
			wallHitHorizontal->x += step->x;
			wallHitHorizontal->y += step->y;
		}
	}
}
