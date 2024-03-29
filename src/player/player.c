/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 18:57:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_square(t_game *game, t_square *square, t_player *player)
{
	square->p_center = malloc(sizeof(t_coord));
	pos_player_map(game->map, player, square);
	square->p_square = malloc(sizeof(t_coord));
	insert_coord(square->p_square, player->square->p_center->x
		- player->tam / 2, player->square->p_center->y - player->tam / 2);
	square->p_left_down = malloc(sizeof(t_coord));
	square->p_right_down = malloc(sizeof(t_coord));
	square->p_left_up = malloc(sizeof(t_coord));
	square->p_right_up = malloc(sizeof(t_coord));
}

//-1 pq el eje y es para abajo el positivo
static void	init_direction(t_player *player)
{
	player->direction = malloc(sizeof(t_coord));
	player->len_dir = 20;
	player->dir_x = 0.0;
	player->dir_y = (player->len_dir * -1);
	update_direction(player);
	pos_line(player);
}

void	update_direction(t_player *player)
{
	insert_coord(player->direction, player->square->p_center->x + player->dir_x,
		player->square->p_center->y + player->dir_y);
}

void	init_player(t_player *player, t_game *game, t_square *square)
{
	player->mlx = game->mlx;
	player->img = game->img;
	player->color = WHITE;
	player->tam = 4;
	player->vel_move = 2.5;
	player->fov = FOV;
	player->screen_x = WIDTH;
	player->screen_y = HEIGHT;
	player->angle = ft_get_player_angle(game->map->tour);
	player->pos_map = malloc(sizeof(t_coord));
	*player->pos_map = ft_get_player_pos(game->map->tour);
	player->p_line = malloc(sizeof(t_point));
	init_square(game, square, player);
	init_direction(player);
	player->distance_proyection = (float)(player->screen_x / 2)
		/ tan(grades_to_rad(player->fov / 2));
	player->txt = malloc(sizeof(t_txt_draw));
	player->txt->wall_hit = malloc(sizeof(t_coord));
}
