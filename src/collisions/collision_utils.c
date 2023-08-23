/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:43:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 19:08:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*split the coord with the advance by the size of the tile and know
what tile is and if we can advance*/

//Check collision of the left down point
int	check_left_down_p(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;
	float	aux_y;

	aux_x = player->square->p_left_down->x + advance_x;
	aux_y = player->square->p_left_down->y + advance_y;
	if (map->tour[(int)aux_y / (int)map->lim][(int)aux_x
		/ (int)map->lim] == '1')
		return (-1);
	return (0);
}

//Check collision of the right down point
int	check_right_down_p(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;
	float	aux_y;

	aux_x = player->square->p_right_down->x + advance_x;
	aux_y = player->square->p_right_down->y + advance_y;
	if (map->tour[(int)aux_y / (int)map->lim][(int)aux_x
		/ (int)map->lim] == '1')
		return (-1);
	return (0);
}

//Check collision of the lef up point
int	check_left_up_p(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;
	float	aux_y;

	aux_x = player->square->p_left_up->x + advance_x;
	aux_y = player->square->p_left_up->y + advance_y;
	if (map->tour[(int)aux_y / (int)map->lim][(int)aux_x
		/ (int)map->lim] == '1')
		return (-1);
	return (0);
}

//Check collision of the right up point
int	check_right_up_p(t_player *player, t_map *map, float advance_x,
		float advance_y)
{
	float	aux_x;
	float	aux_y;

	aux_x = player->square->p_right_up->x + advance_x;
	aux_y = player->square->p_right_up->y + advance_y;
	if (map->tour[(int)aux_y / (int)map->lim][(int)aux_x
		/ (int)map->lim] == '1')
		return (-1);
	return (0);
}
