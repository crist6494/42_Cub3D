/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:08:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/06 19:32:40 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_player(t_player *player, t_game *game)
{
    player->color = WHITE;
    player->tam = 10;
    player->vel_move = 3;
    player->mlx = game->mlx;
    player->img = game->img;
}

void paint_player(t_game *game, t_player *player, float y, float x)
{
    player->p_x = x;
    player->p_y = y;
    init_player(player, game);
    insert_coord(game->coord, y, x);
    square_paint(game->coord, player->tam, player->color, player->img);
}