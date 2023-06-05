/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/05 20:28:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_map(t_map *map)
{
	map->len_x = COL; 
	map->len_y = ROW;
	map->lim = 50;
	map->map_width = map->len_x * map->lim; 
	map->map_height = map->len_y * map->lim;
	map->half_x = (WIDTH - map->map_width) / 2;
	map->half_y = (HEIGHT - map->map_height) / 2;
}

void read_map(t_map *map)
{
	char stage[ROW][COL] = 
	{
		{'1', '1', '1', '1', '1', '1','1','1','1','1'},
        {'1', '0', '0', '0', '0', '0','0','0','0','1'},
        {'1', '0', '0', '1', '1', '0','0','0','0','1'},
        {'1', '0', '0', '1', '1', '1','1','1','0','1'},
        {'1', '0', '0', '1', '1', '1','1','1','0','1'},
        {'1', '0', '0', '0', '1', '1','1','1','0','1'},
        {'1', '0', '0', '0', '1', '1','0','0','0','1'},
        {'1', '0', '0', '0', '1', '1','0','0','0','1'},
        {'1', '0', '0', '0', '0', '0','0','0','0','1'},
        {'1', '1', '1', '1', '1', '1','1','1','1','1'},
	};
	unsigned int y;
	
	init_map(map);
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

void create_map(t_game *game,t_coord *coord, float c_y, float c_x)
{
	unsigned int y;
	float aux_x;
	
	read_map(game->map);
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

void paint_map(t_game *game, t_map *map, t_coord *coord)
{
	init_map(map);
	clear_map(game);
	create_map(game, coord, map->half_y, map->half_x);
	//create_map(game, coord, 50, (WIDTH - map->map_width) - 50);
}