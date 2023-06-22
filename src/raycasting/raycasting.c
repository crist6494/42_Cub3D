/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/22 11:51:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_ray(t_ray *data, float angle)
{
	data->wallHitHorizontal = malloc(sizeof(t_coord));
	//Sacamos direccion que se mueve el rayo
	data->down = 0;
	data->left = 0;
	data->rads_angle = grades_to_rad(angle);
	if(data->rads_angle > (float)0 && data->rads_angle < (float)M_PI)
		data->down = 1;
	if(data->rads_angle > (float)M_PI / 2 && data->rads_angle < 3 * (float)M_PI / 2)
		data->left = 1;
}


void raycast(t_game *game, t_player *player, t_ray *ray)
{
	(void)game;
	init_ray(ray, player->angle);
	raycast_horizonal(game->map, player, ray);
	init_points(player->p_line, player->square->p_center, ray->wallHitHorizontal);//Iniciar linea
   	paint_line(player->p_line, game->img, RED);
}