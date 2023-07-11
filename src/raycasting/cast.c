/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/11 20:34:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t reversecolor(unsigned int coloraux)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = coloraux >> 24;
	green = coloraux << 8 >> 24;
	blue = coloraux << 16 >> 24;
	alpha = coloraux << 24 >> 24;
	return (get_rgba(red, green, blue, alpha));
}

static void render_wall(t_player *player, t_txt_draw *txt,float distance, unsigned int x)
{
	float	distance_proyection;
	int		proyected_height;
	float	height_wall;
	int color;
	proyected_height = 700;
	distance_proyection = (float)(player->screen_x / 2) / (player->fov / 2);
	
	height_wall = ((float)proyected_height / distance) * distance_proyection;
	//txt->acc = 0;
	txt->step = txt->texture->height / height_wall;
	txt->y0 = (player->screen_y / 2) - (height_wall / 2);
	/* if(y0 < 0)
	{
		txt->acc = (-txt->y0 + 1) * txt->step;
		txt->y0 = 0;
	} */
	txt->y1 = txt->y0 + height_wall;
	if(txt->y1 > player->screen_y - 1)
		txt->y1 = player->screen_y - 1;
	while(txt->y0 < txt->y1)
	{
		color = txt->texture->pixels[txt->coord_x_txt + ((txt->y0 * (int)txt->step) * txt->texture->width)];
		if(txt->y0 > 0 && txt->y0 < player->screen_y - 1)
			mlx_put_pixel(player->img, x, txt->y0, (color));
		txt->y0++;
	}
	/* int y0;
	int y1;
	int x0;
	
	//y0 = (player->screen_y / 2) - (height_wall / 2);
	if(y0 < 0)
		y0  = 0;
	y1 = y0 + height_wall;
	x0 = x; */
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
		render_wall(player,game->player->txt, distance, i);
		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
		i++;
	}
}
