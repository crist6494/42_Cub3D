/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/06 20:30:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void player_advance(t_game *game, t_player *player, int direction)
{
	(void)game;
	double	angle;
	float	advance_x;
	float	advance_y;

	angle = (90 * M_PI) / 180;
	if(direction == 1 || direction == -1)
	{
		advance_x = (float)direction * cos(angle) * player->vel_move;
		advance_y = (float)direction * sin(angle) * player->vel_move;
		player->p_x += advance_x;
		player->p_y += advance_y;
	}
	clear_map(game);
	create_map(game, game->coord, game->map->half_y, game->map->half_x);
	paint_player(game, player, player->p_y, player->p_x);
}