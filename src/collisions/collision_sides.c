/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:22:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 19:04:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Check ¨ corner of the square
float	check_up_colli(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_y;

	aux_y = player->square->p_center->y;
	if (check_right_up_p(player, map, advance_x, advance_y) == 0
		&& check_left_up_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		//For can move when is next to a wall
		if (check_right_up_p(player, map, 0, advance_y) == 0
			&& check_left_up_p(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}

//Check .. corner of the square
float	check_down_colli(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_y;

	aux_y = player->square->p_center->y;
	if (check_right_down_p(player, map, advance_x, advance_y) == 0
		&& check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		//For can move when is next to a wall
		if (check_right_down_p(player, map, 0, advance_y) == 0
			&& check_left_down_p(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}

//Check <-: corner of the square
float	check_left_colli(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;

	aux_x = player->square->p_center->x;
	if (check_left_up_p(player, map, advance_x, advance_y) == 0
		&& check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		//For can move when is next to a wall
		if (check_left_up_p(player, map, advance_x, 0) == 0
			&& check_left_down_p(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}

//Check :-> corner of the square
float	check_right_colli(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;

	aux_x = player->square->p_center->x;
	if (check_right_up_p(player, map, advance_x, advance_y) == 0
		&& check_right_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		//For can move when is next to a wall
		if (check_right_up_p(player, map, advance_x, 0) == 0
			&& check_right_down_p(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}
