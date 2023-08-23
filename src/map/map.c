/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 11:55:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Start the key variables of the map
void	init_map(t_game *game, t_map *map, char *path_map)
{
	(void)path_map;
	map->tour = game->comp->map;//The ** map
	map->len_x = ft_get_len_x(game->comp->map);
	map->len_y = ft_get_len_y(game->comp->map);
	map->lim = 30;//All size of each square of the map
	map->width = map->len_x * map->lim;
	map->height = map->len_y * map->lim;
}

/* 
//Paint a minimap of all the map
void	create_map(t_game *game, t_map *map, float c_x, float c_y)
{
	unsigned int	y;
	unsigned int	x;
	float			aux_x;
	t_coord			m_coord;

	insert_coord(&m_coord, c_x, c_y);
	aux_x = c_x;
	y = 0;
	while (y < map->len_y)
	{
		x = 0;
		m_coord.x = aux_x;
		while (x < map->len_x)
		{
			if (map->tour[y][x] == '1')
				square_paint(&m_coord, map->lim, BLACK, game->img);
			else if (map->tour[y][x] == '0')
				square_paint(&m_coord, map->lim, GREY, game->img);
			else if (map->tour[y][x] == 'N' || map->tour[y][x] == 'S'
					|| map->tour[y][x] == 'W' || map->tour[y][x] == 'E')
				square_paint(&m_coord, map->lim, GREY, game->img);
			m_coord.x += map->lim;
			x++;
		}
		m_coord.y += map->lim;
		y++;
	}
} */
