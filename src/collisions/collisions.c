/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:59:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 12:12:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_collision_vertical(t_map *map, t_player *player,
				float advance_x, float advance_y);
static void	check_collision_horizontal(t_map *map, t_player *player,
				float advance_x, float advance_y);
static void	check_collision_diagonal(t_map *map, t_player *player,
				float advance_x, float advance_y);

// Tolerancia pequeña para saber que de cerca esta del 0 
//y lo comparamos con el valor absoluto

void	check_collision(t_map *map, t_player *player, float advance_x,
		float advance_y)
{
	float	tolerance;

	tolerance = 0.0001;
	if (fabs(advance_x) > tolerance && fabs(advance_y) > tolerance)
		check_collision_diagonal(map, player, advance_x, advance_y);
	else if (fabs(advance_x) <= tolerance && fabs(advance_y) > tolerance)
		check_collision_vertical(map, player, advance_x, advance_y);
	else if (fabs(advance_x) > tolerance && fabs(advance_y) <= tolerance)
		check_collision_horizontal(map, player, advance_x, advance_y);
}

static void	check_collision_vertical(t_map *map, t_player *player,
		float advance_x, float advance_y)
{
	float	py;

	py = 0;
	if (advance_y < 0)
		py = check_up_collision(player, map, advance_x, advance_y);
	else
		py = check_down_collision(player, map, advance_x, advance_y);
	player->square->p_center->y = py;
}

static void	check_collision_horizontal(t_map *map, t_player *player,
		float advance_x, float advance_y)
{
	float	px;

	px = 0;
	if (advance_x < 0)
		px = check_left_collision(player, map, advance_x, advance_y);
	else
		px = check_right_collision(player, map, advance_x, advance_y);
	player->square->p_center->x = px;
}

static void	check_collision_diagonal(t_map *map, t_player *player,
		float advance_x, float advance_y)
{
	if (advance_x < 0 && advance_y < 0)
	{
		player->square->p_center->x = check_left_collision(player, map,
				advance_x, advance_y);
		player->square->p_center->y = check_up_collision(player, map, advance_x,
				advance_y);
	}
	else if (advance_x > 0 && advance_y < 0)
	{
		player->square->p_center->x = check_right_collision(player, map,
				advance_x, advance_y);
		player->square->p_center->y = check_up_collision(player, map, advance_x,
				advance_y);
	}
	else if (advance_x > 0 && advance_y > 0)
	{
		player->square->p_center->x = check_right_collision(player, map,
				advance_x, advance_y);
		player->square->p_center->y = check_down_collision(player, map,
				advance_x, advance_y);
	}
	else if (advance_x < 0 && advance_y > 0)
	{
		player->square->p_center->x = check_left_collision(player, map,
				advance_x, advance_y);
		player->square->p_center->y = check_down_collision(player, map,
				advance_x, advance_y);
	}
}
