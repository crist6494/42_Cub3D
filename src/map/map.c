/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/27 19:57:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char **get_map(t_map *map, char *path_map);

void init_map(t_map *map, char *path_map)
{
	map->len_x = get_len_x(path_map);
	map->len_y = get_len_y(path_map);
	map->tour = get_map(map, path_map);
	map->lim = 20;
	map->width = map->len_x * map->lim;
	map->height = map->len_y * map->lim;
	map->mid_map = malloc(sizeof(t_coord));
	map->mid_map->x = (WIDTH - map->width) / 2;
	map->mid_map->y = (HEIGHT - map->height) / 2;
	map->m_coord = malloc(sizeof(t_coord));
}

static char **get_map(t_map *map, char *path_map)
{
	char **tour;
	tour = alloc_map(map);
	fill_map(map, tour);
	fill_values_map(map, tour, path_map);
	return (tour);
}

void create_map(t_game *game, t_map *map, float c_x, float c_y)
{
	unsigned int y;
	unsigned int x;
	float aux_x;
	   
	insert_coord(map->m_coord, c_x, c_y);
	aux_x = c_x;
	y = 0;
	while(y < map->len_y)
	{
		x = 0;
		map->m_coord->x = aux_x;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == '1')
				square_paint(map->m_coord, map->lim, BLACK, game->img);
			else if(map->tour[y][x] == '0')
				square_paint(map->m_coord, map->lim, GREY, game->img);
			else if(map->tour[y][x] == 'N' || map->tour[y][x] == 'S' || map->tour[y][x] == 'W' || map->tour[y][x] == 'E')
				square_paint(map->m_coord, map->lim, GREY, game->img);
			map->m_coord->x += map->lim;
			x++;
		} 
		map->m_coord->y += map->lim;
		y++;
	}
}

void paint_map(t_game *game, t_map *map, char *map_path)
{
	(void)game;
	init_map(map, map_path);
	clear_map(map);
	create_map(game, map, map->mid_map->x, map->mid_map->y);
	//create_map(game, map, 50, (WIDTH - map->width) - 50);
	//free_map(map);
}