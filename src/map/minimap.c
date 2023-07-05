/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:24:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/05 19:18:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#include "cub3D.h"

void paint_minimap_black(t_game *game);

void init_minimap(t_game *game)
{
	(void)game;
	game->minimap = mlx_new_image(game->mlx, 500, 500);
	if(!game->minimap)
		error();
	if (mlx_image_to_window(game->mlx, game->minimap, (WIDTH - 340), 40) < 0)
        error();
	//paint_minimap_black(game);
} 

void paint_minimap_black(t_game *game)
{
	int x;
	int y;

	//printf("Hola\n");
	y = 0;
	while(y < 300)
	{
		x = 0;
		while(x < 300)
		{
			mlx_put_pixel(game->minimap, x, y, WHITE);
			x++;	
		}
		y++;
	}
}

void paint_square(t_paint_p *coord, int lim, uint32_t color, mlx_image_t *img)
{
    int_fast64_t del_x;
    int del_y;
	int y;
	int x;
   
    del_y = lim + coord->y;
    del_x = lim + coord->x;
    y = coord->y;
	x = coord->x;
	while(y <= del_y)
	{
        x = coord->x;
		while(x <= del_x)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;		
	}

}

void paint_minimap(t_game * game)
{
	t_paint_p p;

	p.x = 0;
	p.y = 0;
	paint_minimap_black(game);
	//paint_square(game, RED, &p, 20);
	int	x;
	int	y;
	int	len_x;
	int aux;
	int	len_y;
	int  lim = 30;
	x = (int)game->player->square->p_center->x / (int)game->map->lim - 5;
	y = (int)game->player->square->p_center->y / (int)game->map->lim - 5;
	aux = p.x;
	len_x = x + 11;
	len_y = y + 11;

	while (y < len_y /* && (y >= 0  && y <= (int)game->map->len_y) */)
	{
		x = (int)game->player->square->p_center->x / (int)game->map->lim - 5;
		p.x = aux;
		while (x < len_x /* &&( x >= 0 && x <= (int)game->map->len_x) */)
		{
			printf("LEn_Y: %d\n", len_y);
			printf("Y: %d\n", y);
			printf("X: %d\n", x);
			if(!(y >= 0  && y <= (int)game->map->len_y) || !(x >= 0 && x <= (int)game->map->len_x))
			{
				printf("Sale mapa\n");
			}
			else
			{
				if (game->map->tour[y][x] == '1')
					paint_square(&p, lim, RED, game->minimap);
				else
					paint_square(&p, lim, BLACK, game->minimap);
			}
			p.x += lim;
			x++;
		}
		y++;
		p.y += lim;
	}
}