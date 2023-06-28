/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:43:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/28 19:11:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_left_down_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_left_down->x + advance_x;
	aux_y = player->square->p_left_down->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
		return (-1);
	return (0);
}

int check_right_down_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_right_down->x + advance_x;
	aux_y = player->square->p_right_down->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
		return (-1);
	return (0);
}


int check_left_up_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_left_up->x + advance_x;
	aux_y = player->square->p_left_up->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
		return (-1);
	return (0);
}


int check_right_up_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_right_up->x + advance_x;
	aux_y = player->square->p_right_up->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
		return (-1);
	return (0);
}
