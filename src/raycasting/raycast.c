/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:42:38 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/28 19:47:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_ray(t_ray *data, float angle)
{
/* 	data->coordHitHorizontal = malloc(sizeof(t_coord));
	data->coordHitVertical = malloc(sizeof(t_coord)); */
	//Sacamos direccion que se mueve el rayo
	data->down = 0;
	data->left = 0;
	data->rads_angle = grades_to_rad(angle);
	if(data->rads_angle > (float)0 && data->rads_angle < (float)M_PI)
		data->down = 1;
	if(data->rads_angle > (float)M_PI / 2 && data->rads_angle < 3 * (float)M_PI / 2)
		data->left = 1;
}

static float distance(float px0, float py0, float px1, float py1)
{
	float distance_x;
	float distance_y;
	float distance;

	distance_x = pow(px1 - px0, 2);
	distance_y = pow(py1 - py0, 2);
	distance = sqrt(distance_x + distance_y);
	return (distance);
}

float	raycast(t_game *game, t_player *player, t_ray *ray, float angle)
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
		//insert_coord(ray->coordHitHorizontal, wallHitHorizontal.x, wallHitHorizontal.y);
		init_points(player->p_line, player->square->p_center, &wallHitHorizontal);//Iniciar linea
		//paint_line(player->p_line, game->img, RED);
		return (distance_horizontal);
	}
	else
	{
		//insert_coord(ray->coordHitVertical, wallHitVertical.x, wallHitVertical.y);
		init_points(player->p_line, player->square->p_center, &wallHitVertical);//Iniciar linea
		//paint_line(player->p_line, game->img, RED);
		return (distance_vertical);
	}
}