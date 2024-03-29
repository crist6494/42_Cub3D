/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:42:38 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 18:51:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Sacamos direccion que se mueve el rayo
void	init_ray(t_ray *data, float angle)
{
	data->down = 0;
	data->left = 0;
	data->rads_angle = grades_to_rad(angle);
	if (data->rads_angle > (float)0 && data->rads_angle < (float)M_PI)
		data->down = 1;
	if (data->rads_angle > (float)M_PI / 2 && data->rads_angle < 3 * (float)M_PI
		/ 2)
		data->left = 1;
}

static float	distance(float px0, float py0, float px1, float py1)
{
	float	distance_x;
	float	distance_y;
	float	distance;

	distance_x = pow(px1 - px0, 2);
	distance_y = pow(py1 - py0, 2);
	distance = sqrt(distance_x + distance_y);
	return (distance);
}

void	set_horizontal_texture(t_txt_draw *txt, t_ray *ray, t_game *game)
{
	if (ray->down == 1)
	{
		txt->texture = game->comp->no;
		txt->coord_x_txt = (((int)txt->wall_hit->x % ((int)game->map->lim))
				/ game->map->lim) * (txt->texture->width);
	}
	else
	{
		txt->texture = game->comp->so;
		txt->coord_x_txt = (((int)txt->wall_hit->x % ((int)game->map->lim))
				/ game->map->lim) * (txt->texture->width);
	}
}

void	set_vertical_texture(t_txt_draw *txt, t_ray *ray, t_game *game)
{
	if (ray->left == 1)
	{
		txt->texture = game->comp->ea;
		txt->coord_x_txt = (((int)txt->wall_hit->y % ((int)game->map->lim))
				/ game->map->lim) * (txt->texture->height);
	}
	else
	{
		txt->texture = game->comp->we;
		txt->coord_x_txt = (((int)txt->wall_hit->y % ((int)game->map->lim))
				/ game->map->lim) * (txt->texture->height);
	}
}

float	raycast(t_game *game, t_player *player, t_ray *ray, float angle)
{
	t_coord	wall_hit_hori;
	t_coord	wall_hit_verti;
	float	distance_horizontal;
	float	distance_vertical;

	init_ray(ray, angle);
	raycast_horizonal(game->map, player, ray, &wall_hit_hori);
	raycast_vertical(game->map, player, ray, &wall_hit_verti);
	distance_horizontal = distance(player->square->p_center->x,
			player->square->p_center->y, wall_hit_hori.x, wall_hit_hori.y);
	distance_vertical = distance(player->square->p_center->x,
			player->square->p_center->y, wall_hit_verti.x, wall_hit_verti.y);
	if (distance_horizontal <= distance_vertical)
	{
		insert_coord(player->txt->wall_hit, wall_hit_hori.x, wall_hit_hori.y);
		set_horizontal_texture(player->txt, ray, game);
		return (distance_horizontal);
	}
	else
	{
		insert_coord(player->txt->wall_hit, wall_hit_verti.x, wall_hit_verti.y);
		set_vertical_texture(player->txt, ray, game);
		return (distance_vertical);
	}
}
//init_points(player->p_line, player->square->p_center, &wall_hit_hori);
//paint_line(player->p_line, game->img, RED);
//init_points(player->p_line, player->square->p_center, &wall_hit_verti);
//paint_line(player->p_line, game->img, RED);