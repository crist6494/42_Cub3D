/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 20:16:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void read_map(t_map *map)
{
	char stage[ROW][COL] = 
	{
		{'1', '1', '1', '1', '1', '1','1','1','1','1'},
        {'1', '0', '0', '0', '0', '0','0','0','0','1'},
        {'1', 'W', '0', '1', '1', '0','0','0','0','1'},
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
} */

void create_map(t_game *game, t_map *map, float c_x, float c_y)
{
	unsigned int y;
	float aux_x;
	   
	//read_map(map);
	insert_coord(map->m_coord, c_x, c_y);
	aux_x = c_x;
	y = 0;
	while(y < map->len_y)
	{
		unsigned int x;
		x = 0;
		map->m_coord->x = aux_x;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == '1')
				square_paint(map->m_coord, map->lim, BLACK, game->img);
			else if(map->tour[y][x] == '0')
			{
				square_paint(map->m_coord, map->lim, TEAL, game->img);
			}
			map->m_coord->x += map->lim;
			x++;
		} 
		map->m_coord->x = 0;
		map->m_coord->y += map->lim;
		y++;
	}
}

void paint_map(t_game *game, t_map *map, t_coord *coord)
{
	(void)coord;
	//read_map(map);
	clear_map(game);
	insert_coord(map->m_coord, map->half_x, map->half_y);
	square_paint(map->m_coord, map->lim, RED, game->img);
	//create_map(game, map, map->half_x, map->half_y);
	//paint_player(game, game->player);
	//create_map(game, coord, 50, (WIDTH - map->map_width) - 50);
}