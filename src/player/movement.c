/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/12 20:51:44 by cmorales         ###   ########.fr       */
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

	angle = (player->angle * M_PI) / 180;
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
	angle = grades_to_rad((double)player->angle);
	if(clockwise == 1 || clockwise == -1)
	{
		player->dir_x = (float)player->len_dir * cos(angle);
		player->dir_y = (float)player->len_dir * sin(angle);
		//printf("Player_dir_x: %f\n", player->dir_x);
		//printf("Player_dir_y: %f\n", player->dir_y);
		update_direction(player);
	}
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
	//printf("center_x: %f, center_y: %f\n", player->p_center->x, player->p_center->y);
	//printf("x:%f - x1:%f - y:%f - y1:%f\n\n", player->p_line->x, player->p_line->x1, player->p_line->y, player->p_line->y1);
	clear_map(game->map);
    //paint_line(player->p_line, player->img);
	bresenham(player->p_line->x, player->p_line->y, player->p_line->x1, player->p_line->y1, *game->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
}