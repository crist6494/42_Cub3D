/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:24:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/12 20:46:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void loop_paint_minimap(t_game *game, t_minimap *mp, t_coord *p, int lim);

void init_minimap(t_game *game, t_minimap *minimap, int width, int height)
{
	(void)game;
	minimap->img = mlx_new_image(game->mlx, 331, 331);
	if(!minimap->img)
		error();
	if (mlx_image_to_window(game->mlx, minimap->img, (width - 360), height) < 0)
    	error();
} 

void paint_minimap_background(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(y < 331)
	{
		x = 0;
		while(x < 331)
		{
			mlx_put_pixel(game->minimap->img, x, y, WHITE);
			x++;	
		}
		y++;
	}
}

static int ft_get_map_color(t_map * map, int x, int y)
{
	int color;

	if (map->tour[y][x] == '1')
		color = RED;
	else if (map->tour[y][x] == ' ')
		color = WHITE;
	else
		color = BLACK;
	return (color);
}

void paint_minimap(t_game *game, t_minimap *mp)
{
	t_coord p;
	t_coord c;
	int lim;

	paint_minimap_background(game);
	insert_coord(&p, 0, 0);
	insert_coord(&c, 150, 150);
	lim = 30;
	mp->cas_x = (int)(game->player->square->p_center->x / (int)game->map->lim) - 5;
	mp->cas_y = (int)(game->player->square->p_center->y / (int)game->map->lim) - 5;
	mp->len_x = mp->cas_x + 11;
	mp->len_y = mp->cas_y + 11;
	loop_paint_minimap(game, mp, &p, lim);
	square_paint(&c, 28, GREY, mp->img);
}

static void loop_paint_minimap(t_game *game, t_minimap *mp, t_coord *p, int lim)
{
	int aux;

	aux = p->x;
	while (mp->cas_y < mp->len_y)
	{
		mp->cas_x = (int)game->player->square->p_center->x / (int)game->map->lim - 5;
		p->x = aux;
		while (mp->cas_x < mp->len_x)
		{
			if(!(mp->cas_y >= 0  && mp->cas_y <= (int)game->map->len_y - 1) || !(mp->cas_x >= 0 && mp->cas_x <= (int)game->map->len_x - 1))
				square_paint(p, lim, WHITE, mp->img);
			else
				square_paint(p, lim, ft_get_map_color(game->map, mp->cas_x, mp->cas_y), mp->img);
			p->x += lim;
			mp->cas_x++;
		}
		mp->cas_y++;
		p->y += lim;
	}
}
