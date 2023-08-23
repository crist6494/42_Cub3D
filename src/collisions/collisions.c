/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:59:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 19:10:47 by cmorales         ###   ########.fr       */
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
//y lo comparamos con el valor absoluto por los floats

//Principal fuction to check collision
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

/*If the are collision player square center will be the same, 
if not this variable change and add the advance corresponding*/

//Checkk vertical collision and advance coord y of the player
static void	check_collision_vertical(t_map *map, t_player *player,
		float advance_x, float advance_y)
{
	float	py;

	py = 0;
	if (advance_y < 0)
		py = check_up_colli(player, map, advance_x, advance_y);
	else
		py = check_down_colli(player, map, advance_x, advance_y);
	player->square->p_center->y = py;
}

//Checkk vertical collision and advance coord x of the player
static void	check_collision_horizontal(t_map *map, t_player *player,
		float advance_x, float advance_y)
{
	float	px;

	px = 0;
	if (advance_x < 0)
		px = check_left_colli(player, map, advance_x, advance_y);
	else
		px = check_right_colli(player, map, advance_x, advance_y);
	player->square->p_center->x = px;
}

//Checkk diagonal collision and advance coord x and y of the player
static void	check_collision_diagonal(t_map *map, t_player *player,
		float a_x, float a_y)
{
	if (a_x < 0 && a_y < 0)
	{
		player->square->p_center->x = check_left_colli(player, map, a_x, a_y);
		player->square->p_center->y = check_up_colli(player, map, a_x, a_y);
	}
	else if (a_x > 0 && a_y < 0)
	{
		player->square->p_center->x = check_right_colli(player, map, a_x, a_y);
		player->square->p_center->y = check_up_colli(player, map, a_x, a_y);
	}
	else if (a_x > 0 && a_y > 0)
	{
		player->square->p_center->x = check_right_colli(player, map, a_x, a_y);
		player->square->p_center->y = check_down_colli(player, map, a_x, a_y);
	}
	else if (a_x < 0 && a_y > 0)
	{
		player->square->p_center->x = check_left_colli(player, map, a_x, a_y);
		player->square->p_center->y = check_down_colli(player, map, a_x, a_y);
	}
}
