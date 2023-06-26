/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/26 17:57:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	normalize_angle(float angle)
{
	//float	new_angle;

	//new_angle = angle;
	//ºprintf("Entra\n");
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 360)
		angle = angle - 360;
	return (angle);
}

void init_ray(t_ray *data, float angle)
{
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

	printf("Inicio_x: %f\n", px0);
	printf("Inicio_y: %f\n", py0);
	printf("Final_x: %f\n", px1);
	printf("Final_y: %f\n", py1);


	distance_x = pow(px0 - px1, 2);
	distance_y = pow(py0 - py1, 2);
	distance = sqrt(distance_x + distance_y);
	return (distance);
}

void raycast(t_game *game, t_player *player, t_ray *ray)
{
	t_coord wallHitHorizontal;
	t_coord wallHitVertical;
	float	distance_horizontal;
	float	distance_vertical;
	float angle;

	angle = normalize_angle(player->angle);
	init_ray(ray, angle);
	raycast_horizonal(game->map, player, ray, &wallHitHorizontal);
	raycast_vertical(game->map, player, ray, &wallHitVertical);
	distance_horizontal = distance(player->square->p_center->x, player->square->p_center->y, wallHitHorizontal.x, wallHitHorizontal.y);
	distance_vertical = distance(player->square->p_center->x, player->square->p_center->y, wallHitVertical.x, wallHitVertical.y);
	printf("\n");
	printf("Distancia_vertical: %f\n", distance_vertical);
	printf("Distancia_horizontal: %f\n", distance_horizontal);
	printf("\n");
	if(distance_horizontal <= distance_vertical)
	{
		/* printf("Entra Horizontal\n\n");
		printf("Angle: %d\n", player->angle);
		printf("Angle: %f\n", ray->rads_angle);
		printf("wallHitHorizontal_x: %f\n", wallHitHorizontal.x);
		printf("wallHitHorizontal_y: %f\n", wallHitHorizontal.y); */
		init_points(player->p_line, player->square->p_center, &wallHitHorizontal);//Iniciar linea
		paint_line(player->p_line, game->img, RED);
	}
	else
	{
		/* printf("Entra Vertical\n");
		printf("Angle: %d\n", player->angle);
		printf("Angle: %f\n", ray->rads_angle);
		printf("wallHitVertical_x: %f\n", wallHitVertical.x);
		printf("wallHitVertical_y: %f\n", wallHitVertical.y); */
		init_points(player->p_line, player->square->p_center, &wallHitVertical);//Iniciar linea
		paint_line(player->p_line, game->img, RED);
	}
}
