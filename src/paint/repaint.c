/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repaint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:31:26 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 19:05:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	repaint(t_game *game, t_player *player)
{
	clear_map(game->map);
	paint_ceil_floor(player, game->comp);
	if (BONUS == 1)
		paint_minimap(game, game->minimap);
	cast(game, player, game->ray);
	get_square_corner(player, player->square);
	update_direction(player);
}

	//init_points(player->p_line, player->square->p_center, player->direction);
	//Iniciar linea
	//create_map(game, game->map, 0, 0);
	//paint_line(player->p_line, game->img, WHITE);
	//insert_coord(player->square->p_square, player->square->p_center->x 
		//- player->tam / 2,
	//player->square->p_center->y - player->tam / 2);//Actualizamos cuadrado
	//square_paint(player->square->p_square, player->tam, player->color,
		//player->img);