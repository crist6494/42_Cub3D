/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/24 18:18:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Fuction to set the variables to paint each line of the wall
static void	set_variables_render_wall(t_player *player, t_txt_draw *txt,
		float distance)
{
	int		proyected_height;
	float	height_wall;
	int		half_screen;

	proyected_height = 25;
	/*
		A = ?
		Get the distance to the screen we have the width/2(y) and the angle
		tan(angle) = y / x    x = y / tan(angle)
		B = distance_proyection = distance to the screen
		C = distance ray = we get y rayscast
		D = proyecte heigh(1 that we give)
	*/
	// A/B = C/D  A  = C/D * B
	height_wall = ((float)proyected_height / distance)
		* player->distance_proyection;
	half_screen = player->screen_y / 2;//To start in the middle of the window y to start paint line
	txt->acc = 0;
	txt->step = (float)txt->texture->height / height_wall;//Get the step for paint each texture
	txt->y0 = half_screen - (int)(height_wall / 2);
	if (txt->y0 < 0)//If pass the limit when if < 0
	{
		txt->acc = (-(txt->y0) + 1) * txt->step;
		txt->y0 = 0;
	}
	txt->y1 = txt->y0 + height_wall;//The limit when finish each line
	if (txt->y1 > (int)(player->screen_y - 1))//If pass more than the screen
		txt->y1 = player->screen_y - 1;
}

static void	render_wall(t_player *player, t_txt_draw *txt, float distance,
		unsigned int x)
{
	int	color;

	set_variables_render_wall(player, txt, distance);
	while (txt->y0 < txt->y1)//The start to the end of each line
	{
		//Get each line the pixel of each texture whichever of the following applies 
		//We can only accesss in 1 array so have to * for width to access to next line of texture color
		color = ((unsigned int *)txt->texture->pixels)[(txt->coord_x_txt
				+ (int)txt->acc * txt->texture->width)];
		if (txt->y0 > 0 && txt->y0 <= (int)(player->screen_y - 1))
			mlx_put_pixel(player->img, x, txt->y0, reversecolor(color));//The color give backwards in bits
		if ((float)(txt->acc + txt->step) < (float)txt->texture->height)
			txt->acc += txt->step;
		txt->y0++;
	}
}

//Fuction to render the wall in 3D
void	cast(t_game *game, t_player *player, t_ray *ray)
{
	float			init_angle;
	float			increment_angle;
	unsigned int	i;
	float			distance;
	float			aux;

	i = 0;
	increment_angle = (float)player->fov / WIDTH;//Know the distance of each angle for each ray
	init_angle = player->angle - (float)(player->fov / 2);//Start \|/ in the left to be in the middle
	init_angle = normalize_angle(init_angle);//Be sure no pass 360º
	while (i < WIDTH)//i is each ray and finish whe cover all the width
	{
		aux = game->player->angle - init_angle;
		aux = normalize_angle(aux);
		aux = grades_to_rad(aux);
		distance = cos(aux) * raycast(game, player, ray, init_angle);//Avoid eye fish cos angle * distance of each ray(hypotenuse)
		render_wall(player, game->player->txt, distance, i);//Paint each line of wall
		init_angle += increment_angle;//Pass next ray
		init_angle = normalize_angle(init_angle);
		i++;
	}
}
