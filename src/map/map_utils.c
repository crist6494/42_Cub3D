/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:25:01 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/11 12:57:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void map_print(t_map *map)
{
	unsigned int y;
	y = 0;
	while(y < map->len_y)
	{
		unsigned int x;
		x = 0;
		while(x < map->len_x)
		{
			//printf("El valor de x es: %c\n", map->tour[y][x]);
			x++;
		}
		printf("El valor de y es: %s\n", map->tour[y]);
		y++;
	}
}

void	clear_map(t_map *map)
{
	unsigned int y;
	unsigned int x;
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(map->img, x, y, 0x4a4747FF);
			x++;
		}
		y++;
	}
}

void free_map(t_map *map)
{
	unsigned int y;
	y = 0;
	while(y < map->len_y)
	{
		free(map->tour[y]);
		y++;
	}
	free(map->tour);
	free(map->m_coord);
}