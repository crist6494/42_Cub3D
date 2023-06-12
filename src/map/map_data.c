/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:25:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/12 20:22:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_player_angle(t_map *map)
{
	unsigned int y;
	unsigned int x;

	y = 0;
	while(y < map->len_y)
	{
		x = 0;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == 'N')
				return (270);
			if(map->tour[y][x] == 'S')
				return (90);
			if(map->tour[y][x] == 'W')
				return (180);
			if(map->tour[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (-1);
}

t_coord get_player_pos(t_map *map)
{
	unsigned int y;
	unsigned int x;
	t_coord pos;

	y = 0;
	while(y < map->len_y)
	{
		x = 0;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == 'N' || 
				map->tour[y][x] == 'S' || 
				map->tour[y][x] == 'W' ||
				map->tour[y][x] == 'E')
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	printf("ERROR: not player in the map");
	exit(0);
}