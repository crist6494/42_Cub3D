/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/13 20:52:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		player->p_center->x += advance_x;
		player->p_center->y += advance_y;
	}
	clear_map(game->map);
	create_map(game, game->map, game->map->mid_map->x, game->map->mid_map->y);
	insert_coord(player->mid_square, player->p_center->x - player->tam / 2, 
        player->p_center->y - player->tam / 2);
	update_direction(player);
	init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, player->p_center, player->direction, player->img);
    //bresenham(player->p_line->x,player->p_line->y, player->p_line->x1, player->p_line->y1, *game->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
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
		angle = (angle_rotate * M_PI) / 180;
		advance_x = cos(angle) * (float)player->vel_move;
		advance_y = sin(angle) * (float)player->vel_move;
		player->p_center->x += advance_x;
		player->p_center->y += advance_y;
	}
	clear_map(game->map);
	create_map(game, game->map, game->map->mid_map->x, game->map->mid_map->y);
	insert_coord(player->mid_square, player->p_center->x - player->tam / 2, 
        player->p_center->y - player->tam / 2);
	update_direction(player);
	init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    //bresenham(player->p_line->x,player->p_line->y, player->p_line->x1, player->p_line->y1, *game->img);
    paint_line(player->p_line, player->p_center, player->direction, player->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
}


float grades_to_rad(double angle)
{
	float res;

	res = (angle * M_PI) / 180;
	return (res);
}

//CLockwise = 1  12-3-6-9-12
//CLockwise = -1  12-9-6-3-12


void rotate(t_game *game, t_player *player, int clockwise)
{
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
		update_direction(player);
	}
	clear_map(game->map);
	create_map(game, game->map, game->map->mid_map->x, game->map->mid_map->y);
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, player->p_center, player->direction, player->img);
	//bresenham(player->p_line->x, player->p_line->y, player->p_line->x1, player->p_line->y1, *game->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
}
