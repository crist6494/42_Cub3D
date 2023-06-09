/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:03:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 17:13:53 by cmorales         ###   ########.fr       */
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
	clear_map(game);
	create_map(game, game->map, game->map->half_x, game->map->half_y);
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
	player->angle = 0;
	//printf("Coord x: %f\n", player->direction->x);
	//printf("Coord y: %f\n", player->direction->y);
	if(clockwise == 1)
		player->angle += 3;
	if(clockwise == -1)
		player->angle -= 3;
	if (player->angle < 0)
		player->angle = 360 + player->angle;
	else if (player->angle > 360) 
		player->angle = (int)player->angle % 360;
	angle = grades_to_rad((double)player->angle);
	printf("Angulo%f\n", angle);
	if(clockwise == 1 || clockwise == -1)
	{
		player->dir_x = (float)player->len_dir * cos(angle);
		player->dir_y = (float)player->len_dir * sin(angle);
		printf("!%f\n",player->dir_x);
		printf("!%f\n",player->dir_y);
		update_direction(player);
	}
	clear_map(game);
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
	printf("x:%f - x1:%f - y:%f - y1:%f\n\n", player->p_line->x, player->p_line->x1, player->p_line->y, player->p_line->y1);
    paint_line(player->p_line, player->img);
    ///insert_coord(player->p_center, game->map->half_x - player->tam / 2, game->map->half_y - player->tam / 2);//Pintar el cuadrado en medio
    //square_paint(player->p_center, player->tam, player->color, player->img);
}