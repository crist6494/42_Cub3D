/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/19 22:45:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_direction(t_player *player)
{
    player->direction = malloc(sizeof(t_coord));
    player->len_dir = 30;
    player->dir_x = 0.0;
    player->dir_y = (player->len_dir * -1); //-1 pq el eje y es para abajo el positivo
    update_direction(player); //Iniciamos la direcciona de la linea
    pos_line(player);//Ponemos en que direccion va
}

void update_direction(t_player *player)
{
    insert_coord(player->direction, player->square->p_center->x + player->dir_x, player->square->p_center->y + player->dir_y);
}

void init_player(t_player *player, t_game *game, t_square *square)
{
   // insert_coord(player->p_center, WIDTH / 2, HEIGHT / 2);//Punto medio
    player->mlx = game->mlx;
    player->img = game->img;
    player->color = WHITE;
    player->tam = 8;
    player->vel_move = 2;
    player->angle = get_player_angle(game->map);
    player->pos_map = malloc(sizeof(t_coord));
    *player->pos_map = get_player_pos(game->map);
    square->p_center = malloc(sizeof(t_coord));
    pos_player_map(game->map, player, square);
    square->mid_square = malloc(sizeof(t_coord));
    insert_coord(square->mid_square, player->square->p_center->x - player->tam / 2, 
        player->square->p_center->y - player->tam / 2);//Pintar el cuadrado en medio
    square->p_left_down = malloc(sizeof(t_coord));
    square->p_right_down = malloc(sizeof(t_coord));
    square->p_left_up = malloc(sizeof(t_coord));
    square->p_right_up = malloc(sizeof(t_coord));
    player->p_line = malloc(sizeof(t_point));
    init_direction(player);
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

void pos_player_map(t_map *map, t_player *player, t_square *square)
{
    float square_x;
    float square_y;
    float px;
    float py;
    //square_x = player->pos_map->x * map->lim + map->mid_map->x;
    //square_y = player->pos_map->y * map->lim + map->mid_map->y;
    square_x = player->pos_map->x * map->lim;
    square_y = player->pos_map->y * map->lim;
    px = square_x + (map->lim / 2);
    py = square_y + (map->lim / 2);
    insert_coord(square->p_center, px, py);    
    //insert_coord(player->pos_map, px, py);
    //square_paint(player->p_center, 1, RED, player->img);
}

