/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:31:26 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/11 19:19:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void repaint(t_game *game, t_player *player)
{
	clear_map(game->map);
	paint_ceil_floor(player);
	paint_minimap(game, game->minimap);
	create_map(game, game->map, 0, 0);
	cast(game, player, game->ray);
	init_points(player->p_line, player->square->p_center, player->direction);//Iniciar linea
    paint_line(player->p_line, game->img, WHITE);
	insert_coord(player->square->p_square, player->square->p_center->x - player->tam / 2, 
        player->square->p_center->y - player->tam / 2);//Actualizamos cuadrado
    square_paint(player->square->p_square, player->tam, player->color, player->img);
	get_square_corner(player, player->square);//COjemos las 4 squinas cuadrado
	update_direction(player);//actualizamos punto linea
}
