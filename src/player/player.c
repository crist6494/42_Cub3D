/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/14 20:51:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
    
static void init_direction(t_player *player)
{
    player->direction = malloc(sizeof(t_coord));
    player->len_dir = 40;
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
    player->mlx = game->mlx;
    player->img = game->img;
    player->color = WHITE;
    player->tam = 10;
    player->vel_move = 3;
    player->angle = get_player_angle(game->map);
    player->p_center = malloc(sizeof(t_coord));
    insert_coord(player->p_center, WIDTH / 2, HEIGHT / 2);//Punto medio
    player->mid_square = malloc(sizeof(t_coord));
    insert_coord(player->mid_square, player->p_center->x - player->tam / 2, 
        player->p_center->y - player->tam / 2);//Pintar el cuadrado en medio
    player->p_line = malloc(sizeof(t_point));
    init_direction(player);
  /*   player->pos_map = malloc(sizeof(t_coord));
    player->pos_map = get_player_pos(game->map);
    printf("Pos x: %f", player->pos_map->x);
    printf("Pos y: %f", player->pos_map->y); */
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
    //angle = grades_to_rad(angle);
    //printf("%d\n", player->angle);
    update_direction(player);
}

void paint_player(t_game *game, t_player *player)
{
    //clear_map(game->map);
    init_player(player, game);
    pos_line(player);
    init_points(player->p_line, player->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, game->img);
    square_paint(player->mid_square, player->tam, player->color, player->img);
    //free_player(game->player);
}