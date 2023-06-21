/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:50:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/21 19:22:10 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_player(t_player *player)
{
	free(player->direction);
	free(player->p_line);
	free(player->pos_map);
	free(player->square->p_center);
	free(player->square->mid_square);
	free(player->square->p_left_down);
	free(player->square->p_right_down);
}

float grades_to_rad(float angle)
{
	float res;

	res = (angle * M_PI) / 180;
	return (res);
}