/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/11 14:13:14 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void player_advance(t_game *game, t_player *player, int direction)
{
	(void)game;
	double	angle;
	float	advance_x;
	float	advance_y;

	(void)advance_x;
	(void)advance_y;

	angle = (90 * M_PI) / 180;
	if(direction == 1 || direction == -1)
	{
		advance_x = (float)direction * cos(angle) * player->vel_move;
		advance_y = (float)direction * sin(angle) * player->vel_move;
		//player->position->x += advance_x;
		//player->position->y += advance_y;
	}
	clear_map(game->map);
	//paint_player(game, player);
}

double grades_to_rad(double angle)
{
	double res;

	res = (angle * M_PI) / 180;
	return (res);
}

//CLockwise = 1  12-3-6-9-12
//CLockwise = -1  12-9-6-3-12

void rotate(t_game *game, t_player *player, int clockwise)
{
	double angle;
	(void)angle;
	if(clockwise == 1)
		player->angle += 3;
	if(clockwise == -1)
		player->angle -= 3;
/* 	if (player->angle < 0)
		player->angle = 360 + player->angle;
	else if (player->angle > 360) 
		player->angle = (int)player->angle % 360; */
	angle = grades_to_rad((double)player->angle);
	if(clockwise == 1 )
	{
		player->dir_x = (float)player->len_dir * 2;
		player->dir_y = (float)player->len_dir * 2;
		update_direction(player);
	}
	if(clockwise == -1)
	{
		player->dir_x = (float)player->len_dir / 2;
		player->dir_y = (float)player->len_dir / 2;
		update_direction(player);
	}
	printf("x:%f - x1:%f - y:%f - y1:%f\n\n", player->p_line->x, player->p_line->x1, player->p_line->y, player->p_line->y1);
	clear_map(game->map);
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, player->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
}