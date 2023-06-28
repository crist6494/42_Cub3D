/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:50:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/28 19:37:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void pos_player_map(t_map *map, t_player *player, t_square *square)
{
    float square_x;
    float square_y;
    float px;
    float py;
    //square_x = player->pos_map->x * map->lim + map->p_map->x;
    //square_y = player->pos_map->y * map->lim + map->p_map->y;
    square_x = player->pos_map->x * map->lim;
    square_y = player->pos_map->y * map->lim;
    px = square_x + (map->lim / 2);
    py = square_y + (map->lim / 2);
    insert_coord(square->p_center, px, py);    
    //insert_coord(player->pos_map, px, py);
    //square_paint(player->p_center, 1, RED, player->img);
}

void get_square_corner(t_player *player, t_square *square)
{
	square->p_left_down->x = square->p_center->x - player->tam / 2;
	square->p_left_down->y = square->p_center->y + player->tam / 2;
	
	square->p_right_down->x = square->p_center->x + player->tam / 2;
	square->p_right_down->y = square->p_center->y + player->tam / 2;

	square->p_left_up->x = square->p_center->x - player->tam / 2;
	square->p_left_up->y = square->p_center->y - player->tam / 2;

	square->p_right_up->x = square->p_center->x + player->tam / 2;
	square->p_right_up->y = square->p_center->y - player->tam / 2;

/* 	square_paint(player->square->p_left_down, 0.1, CYAN, player->img);
	square_paint(player->square->p_right_down, 0.1, CYAN, player->img);
	square_paint(player->square->p_left_up, 0.1, CYAN, player->img);
	square_paint(player->square->p_right_up, 0.1, CYAN, player->img); */
}
void pos_line(t_player *player)
{
    if(player->angle == N)
    {
        player->dir_x = (float)player->len_dir * sin(0);
        player->dir_y = (float)player->len_dir * -cos(0);
    }
    if(player->angle == S)
    {
        player->dir_x = (float)player->len_dir * sin(0);
        player->dir_y = (float)player->len_dir * cos(0);
    }
    if(player->angle == W)
    {
        player->dir_x = (float)player->len_dir * -cos(0);
        player->dir_y = (float)player->len_dir * sin(0);
    }
    if(player->angle == E)
    {
        player->dir_x = (float)player->len_dir * cos(0);
        player->dir_y = (float)player->len_dir * sin(0);
    }
    update_direction(player);
}

void free_player(t_player *player)
{
	free(player->direction);
	free(player->p_line);
	free(player->pos_map);
	free(player->square->p_center);
	free(player->square->p_square);
	free(player->square->p_left_down);
	free(player->square->p_right_down);
	free(player->square->p_left_up);
	free(player->square->p_right_up);
}
