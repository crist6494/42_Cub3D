/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/26 20:43:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 360)
		angle = angle - 360;
	return (angle);
}

void init_ray(t_ray *data, float angle)
{
	data->coordHitHorizontal = malloc(sizeof(t_coord));
	data->coordHitVertical = malloc(sizeof(t_coord));
	//Sacamos direccion que se mueve el rayo
	data->down = 0;
	data->left = 0;
	data->rads_angle = grades_to_rad(angle);
	if(data->rads_angle > (float)0 && data->rads_angle < (float)M_PI)
		data->down = 1;
	if(data->rads_angle > (float)M_PI / 2 && data->rads_angle < 3 * (float)M_PI / 2)
		data->left = 1;
}


float distance(float px0, float py0, float px1, float py1)
{
	float distance_x;
	float distance_y;
	float distance;

	distance_x = pow(px1 - px0, 2);
	distance_y = pow(py1 - py0, 2);
	distance = sqrt(distance_x + distance_y);
	return (distance);
}

void raycast(t_game *game, t_player *player, t_ray *ray, float angle)
{
	t_coord wallHitHorizontal;
	t_coord wallHitVertical;
	float	distance_horizontal;
	float	distance_vertical;

	init_ray(ray, angle);
	raycast_horizonal(game->map, player, ray, &wallHitHorizontal);
	raycast_vertical(game->map, player, ray, &wallHitVertical);
	distance_horizontal = distance(player->square->p_center->x, player->square->p_center->y, wallHitHorizontal.x, wallHitHorizontal.y);
	distance_vertical = distance(player->square->p_center->x, player->square->p_center->y, wallHitVertical.x, wallHitVertical.y);
	if(distance_horizontal <= distance_vertical)
	{
		insert_coord(ray->coordHitHorizontal, wallHitHorizontal.x, wallHitHorizontal.y);
		init_points(player->p_line, player->square->p_center, &wallHitHorizontal);//Iniciar linea
		paint_line(player->p_line, game->img, RED);
	}
	else
	{
		insert_coord(ray->coordHitVertical, wallHitVertical.x, wallHitVertical.y);
		init_points(player->p_line, player->square->p_center, &wallHitVertical);//Iniciar linea
		paint_line(player->p_line, game->img, RED);
	}
}


void range_ray(t_game *game, t_player *player, t_ray *ray)
{
	float init_angle;
	float increment_angle;
	int i;
	
	i = 0;
	//printf("Angulo: %d\n", player->angle);
	increment_angle = (float)FOV / WIDTH;
	init_angle = player->angle - (float)(FOV / 2);
	init_angle = normalize_angle(init_angle);
	while(i < WIDTH)
	{
		raycast(game,player, ray, init_angle);
		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
		i++;
	}
}
