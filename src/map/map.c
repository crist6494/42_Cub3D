/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/13 21:05:28 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_map(t_game *game, t_map *map, char *path_map)
{
	(void)path_map;
	map->tour = game->comp->map;
	map->len_x = ft_get_len_x(game->comp->map);
	map->len_y = ft_get_len_y(game->comp->map);
	map->lim = 30;
	map->width = map->len_x * map->lim;
	map->height = map->len_y * map->lim;
	map->mid_map = malloc(sizeof(t_coord));
	map->mid_map->x = (WIDTH - map->width) / 2;
	map->mid_map->y = (HEIGHT - map->height) / 2;
	map->m_coord = malloc(sizeof(t_coord));
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
