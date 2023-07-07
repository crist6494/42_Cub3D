/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/07 18:53:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void render_wall(t_player *player, float distance, unsigned int x)
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
void cast(t_game *game, t_player *player, t_ray *ray)
{
	float init_angle;
	float increment_angle;
	unsigned int i;
	float distance;
	float aux;

	i = 0;
	increment_angle = (float)player->fov / WIDTH;//Saber distancia entre cada grado
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
