/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 18:43:21 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_variables_render_wall(t_player *player, t_txt_draw *txt,
		float distance)
{
	int		proyected_height;
	float	height_wall;
	int		half_screen;

	proyected_height = 25;
	height_wall = ((float)proyected_height / distance)
		* player->distance_proyection;
	half_screen = player->screen_y / 2;
	txt->acc = 0;
	txt->step = (float)txt->texture->height / height_wall;
	txt->y0 = half_screen - (int)(height_wall / 2);
	if (txt->y0 < 0)
	{
		txt->acc = (-(txt->y0) + 1) * txt->step;
		txt->y0 = 0;
	}
	txt->y1 = txt->y0 + height_wall;
	if (txt->y1 > (int)(player->screen_y - 1))
		txt->y1 = player->screen_y - 1;
}

static void	render_wall(t_player *player, t_txt_draw *txt, float distance,
		unsigned int x)
{
	int	color;

	set_variables_render_wall(player, txt, distance);
	while (txt->y0 < txt->y1)
	{
		color = ((unsigned int *)txt->texture->pixels)[(txt->coord_x_txt
				+ (int)txt->acc * txt->texture->width)];
		if (txt->y0 > 0 && txt->y0 <= (int)(player->screen_y - 1))
			mlx_put_pixel(player->img, x, txt->y0, reversecolor(color));
		if ((float)(txt->acc + txt->step) < (float)txt->texture->height)
			txt->acc += txt->step;
		txt->y0++;
	}
}

void	cast(t_game *game, t_player *player, t_ray *ray)
{
	float			init_angle;
	float			increment_angle;
	unsigned int	i;
	float			distance;
	float			aux;

	i = 0;
	increment_angle = (float)player->fov / WIDTH;
	init_angle = player->angle - (float)(player->fov / 2);
	init_angle = normalize_angle(init_angle);
	while (i < WIDTH)
	{
		aux = game->player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rad(aux);
		distance = cos(aux) * raycast(game, player, ray, init_angle);
		render_wall(player, game->player->txt, distance, i);
		init_angle += increment_angle;
		init_angle = normalize_angle(init_angle);
		i++;
	}
}
