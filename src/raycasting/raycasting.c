/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/27 20:11:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void render_wall(t_player *player, float distance, unsigned int x);

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
		insert_coord(ray->coordHitHorizontal, wallHitHorizontal.x, wallHitHorizontal.y);
		init_points(player->p_line, player->square->p_center, &wallHitHorizontal);//Iniciar linea
		//paint_line(player->p_line, game->img, RED);
		return (distance_horizontal);
	}
	else
	{
		insert_coord(ray->coordHitVertical, wallHitVertical.x, wallHitVertical.y);
		init_points(player->p_line, player->square->p_center, &wallHitVertical);//Iniciar linea
		//paint_line(player->p_line, game->img, RED);
		return (distance_vertical);
	}
}


void range_ray(t_game *game, t_player *player, t_ray *ray)
{
	float init_angle;
	float increment_angle;
	unsigned int i;
	float distance;
	float aux;

	i = 0;
	increment_angle = (float)player->fov / WIDTH;
	init_angle = player->angle - (float)(player->fov / 2);
	init_angle = normalize_angle(init_angle);
	while(i < WIDTH)
	{
		aux = game->player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rad(aux);
		distance = cos(aux) * raycast(game,player, ray, init_angle);
		render_wall(player, distance, i);
		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
		i++;
	}
}

void render_wall(t_player *player, float distance, unsigned int x)
{
	float	distance_proyection;
	int		proyected_height;
	float	height_wall;

	proyected_height = 500;
	distance_proyection = (float)(player->screen_x / 2) / (player->fov / 2);
	height_wall = ((float)proyected_height / distance) * distance_proyection;
	
	int y0;
	int y1;
	int x0;
	
	y0 = (player->screen_y / 2) - (height_wall / 2);
	if(y0 < 0)
		y0  = 0;
	y1 = y0 + height_wall;
	x0 = x;

	while(y0 < y1)
	{
		if(y0 > 0 && y0 < player->screen_y - 1)
			mlx_put_pixel(player->img, x0, y0, BLACK);
		y0++;
	}
}