/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/12 00:28:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* punto que es p center
 y apartir de ese punto una line con el dir
 ----------*  y movemos el punto y en avanzar y la line en rotar*/

void player_advance(t_game *game, t_player *player, int direction)
{
	float	angle;
	float	advance_x;
	float	advance_y;
	angle = ((float)player->angle * M_PI) / 180;
	if(direction == 1 || direction == -1)
	{
		advance_x = (float)direction * cos(angle) * player->vel_move;
		advance_y = (float)direction * sin(angle) * player->vel_move;
		check_collision(game->map, player, advance_x, advance_y);
	}
}

void player_lateral(t_game *game, t_player *player, int direction)
{
	float	angle;
	float	advance_x;
	float	advance_y;
	float	angle_rotate;

	if(direction == -1)
		angle_rotate = (float)player->angle - 90;
	if(direction == 1)
		angle_rotate = (float)player->angle + 90;
	if(direction == 1 || direction == -1)
	{
		angle = grades_to_rad(angle_rotate);
		advance_x = cos(angle) * (float)player->vel_move;
		advance_y = sin(angle) * (float)player->vel_move;
		check_collision(game->map, player, advance_x, advance_y);
	}
}

//CLockwise = 1  12-3-6-9-12
//CLockwise = -1  12-9-6-3-12

void rotate(t_game *game, t_player *player, int clockwise)
{
	(void)game;
	float angle;
	
	if(clockwise == 1)
		player->angle += 3;
	if(clockwise == -1)
		player->angle -= 3;
	if (player->angle < 0)
		player->angle = 360 + player->angle;
	else if (player->angle > 360)
		player->angle = player->angle % 360;
	angle = grades_to_rad((float)player->angle);
	if(clockwise == 1 || clockwise == -1)
	{
		player->dir_x = (float)player->len_dir * cos(angle);
		player->dir_y = (float)player->len_dir * sin(angle);
		update_direction(player);//Actualizamos la linea
	}
}
