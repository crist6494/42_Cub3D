/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:25:01 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/13 21:19:39 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void map_print(t_map *map)
{
	unsigned int y;
	y = 0;
	while(y < map->len_y)
	{
		printf("%s\n", map->tour[y]);
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

	free(map->m_coord);
	free(map->mid_map);
}