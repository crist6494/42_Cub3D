/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:24:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/04 20:43:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "cub3D.h"

void paint_minimap_black(t_game *game);

void init_minimap(t_game *game)
{
	(void)game;
	game->minimap = mlx_new_image(game->mlx, 300, 300);
	if(!game->minimap)
		error();
	if (mlx_image_to_window(game->mlx, game->minimap, (WIDTH - 300), 20) < 0)
        error();
	paint_minimap_black(game);
} 

void paint_minimap_black(t_game *game)
{
	int x;
	int y;

	printf("Hola\n");
	y = 0;
	while(y == 250)
	{
		x = 0;
		while(x == 250)
		{
			mlx_put_pixel(game->minimap, x, y, RED);
			x++;	
		}
		y++;
	}
}

void paint_minimap(t_game * game)
{
	paint_minimap_black(game);
/* 	int	x;
	int	y;
	int	len_x;
	int	len_y;

	x = (int)game->player->square->p_center->x / (int)game->map->lim - 3;
	y = (int)game->player->square->p_center->y / (int)game->map->lim - 3;
	len_x = x + 200;
	len_y = y + 200;

	while (y < len_y && y >= 0  && y < (int)game->map->len_y - 1)
	{
		x = 0;
		while (x < len_x && x >= 0 && x < (int)game->map->len_x - 1)
		{
			if (game->map->tour[y][x] == '1' && game->map->tour[y][x] != ' ')
				mlx_put_pixel(game->minimap, x, y, RED);
			else
				mlx_put_pixel(game->minimap, x, y, BLACK);
			//paint_square(game, getmapcolour(game, x, y), c_x, c_y, 10);
			x++;
		}
		y++;
	}   */
}