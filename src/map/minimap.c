/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:24:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/29 12:14:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_minimap(t_game *game)
{
	(void)game;
	game->minimap = mlx_new_image(game->mlx, 300, 300);
	if(!game->minimap)
		error();
	if (mlx_image_to_window(game->mlx, game->minimap, (WIDTH - 300), 20) < 0)
        error();
} 
static unsigned int	getmapcolour(t_game *game, unsigned int i, unsigned int j)
{
	unsigned int	hex;
	int				mapx;
	int				mapy;

	(void)i;
	(void)j;
	hex = 0x050020CC;
	mapx = (int)game->player->square->p_center->x / (int)game->map->lim + i;
	mapy = (int)game->player->square->p_center->y / (int)game->map->lim + j;
	if (mapx >= 0 && mapx < (int)game->map->len_x - 1
		&&mapy >= 0  && mapy < (int)game->map->len_y - 1)
		if (game->map->tour[mapy][mapx] == '1'
			&& game->map->tour[mapy][mapx] != ' ')
			hex = 0x100070CC;
	return (hex);
}

void paint_minimap(t_game * game)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < 250)
	{
		x = 0;
		while (x < 250)
		{
			mlx_put_pixel(game->minimap, x, y, getmapcolour(game, x, y));
			x++;
		}
		y++;
	}
}