/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 16:56:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_direction(t_player *player)
{
    player->direction = malloc(sizeof(t_coord));
    player->len_dir = 80;
    player->dir_x = 0.0;
    player->dir_y = (player->len_dir * -1); //-1 pq el eje y es para abajo el positivo
    update_direction(player); //Iniciamos la direcciona de la linea
}

void update_direction(t_player *player)
{
    insert_coord(player->direction, player->p_center->x + player->dir_x, player->p_center->y + player->dir_y);
}

void init_player(t_player *player, t_game *game)
{
    player->p_center = malloc(sizeof(t_coord));
    insert_coord(player->p_center, game->map->half_x, game->map->half_y);//Punto medio
    player->p_line = malloc(sizeof(t_point));
    player->color = WHITE;
    player->tam = 10;
    player->vel_move = 3;
    player->mlx = game->mlx;
    player->img = game->img;
    init_direction(player);
}

void paint_player(t_game *game, t_player *player)
{
    clear_map(game);
    init_player(player, game);
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, player->img);
    
    //insert_coord(player->p_center, player->p_center->x - player->tam / 2, player->p_center->y - player->tam / 2);//Pintar el cuadrado en medio
    //square_paint(player->p_center, player->tam, player->color, player->img);
    //printf("x0: %f\n", player->p_line->x);
    //printf("x1: %f\n", player->p_line->x1);
    //printf("y0: %f\n", player->p_line->y);
    //printf("y1: %f\n", player->p_line->y1);
}