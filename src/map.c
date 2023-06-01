/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/01 11:48:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_map(t_map *map)
{
	map->len_x = 7; 
	map->len_y = 7;
	map->lim = 50;
	map->map_width = map->len_x * map->lim; 
	map->map_height = map->len_y * map->lim;
	map->half_x = (WIDTH - map->map_width) / 2;
	map->half_y = (HEIGHT - map->map_height) / 2;
}

static void read_map(t_map *map, char stage[7][7])
{
	unsigned int y;
	
	//init_map(map);
	y = 0;
	map->tour = malloc(sizeof(char *) * map->len_y);
	if(!map->tour)
	{
		printf("Can't asign memory in tour char **\n");
		return ;
	}
	while(y < map->len_y)
	{
		unsigned int x;
		x = 0;
		map->tour[y] = malloc(sizeof(char) * map->len_x);
		if(!map->tour[y])
		{
			printf("Can't asign memory in tour char\n");
			return ;
		}
		while(x < map->len_x)
		{
			map->tour[y][x] = (stage[y][x]);
			x++;	
		}
		map->tour[y][x] = '\0';
		y++;
	}
}

void map_print(t_map *map, char stage[7][7])
{
	unsigned int y;
	read_map(map, stage);
	y = 0;
	while(y < map->len_y)
	{
		unsigned int x;
		x = 0;
		while(x < map->len_x)
		{
			printf("El valor de x es: %c\n", map->tour[y][x]);
			x++;
		}

		printf("El valor de y es: %s\n", map->tour[y]);
		y++;
	}
}

void create_map(t_game *game,t_coord *coord,char stage[7][7], float c_y, float c_x)
{
	unsigned int y;
	float aux_x;
	
	read_map(game->map, stage);
	insert_coord(coord, c_y, c_x);
	aux_x = c_x;
	y = 0;
	while(y < game->map->len_y)
	{
		unsigned int x;
		x = 0;
		coord->x = aux_x;
		while(x < game->map->len_x)
		{
			if(game->map->tour[y][x] == '1')
				square_paint(coord, game->map->lim, BLACK, game->img);
			else
				square_paint(coord, game->map->lim, GREY, game->img);
			coord->x += game->map->lim;
			x++;
		}
		coord->x = 0;
		coord->y += game->map->lim;
		y++;
	}
}

void	clear_map(t_game *game, char stage[7][7])
{
	//read_map(game->map, stage);
	(void)stage;
	unsigned int y;
	unsigned int x;
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(game->img, x, y, 0x4a4747FF);
			x++;
		}
		y++;
	}
}