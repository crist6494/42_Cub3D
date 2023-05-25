/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/25 20:32:39 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void init_map(t_map *map)
{
	map->len_x = 7; 
	map->len_y = 7;
}

void read_map(t_map *map, char stage[7][7])
{
	int y;
	
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
		int x;
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
	int y;
	read_map(map, stage);
	y = 0;
	while(y < map->len_y)
	{
		int x;
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

void create_map(t_map *map, mlx_image_t *img, char stage[7][7], t_coord *coord)
{
	read_map(map, stage);
	int y;
	int lim = 50;
	
	int map_width = map->len_x * lim;
	int map_height = map->len_y * lim; 
	
	y = 0;
	coord->y = (HEIGHT - map_height) / 2; 
	while(y < map->len_y)
	{
		coord->x = (WIDTH - map_width) / 2;
		int x;
		x = 0;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == '1')
				square_paint(coord, 50, BLACK, img);
			else
				square_paint(coord, 50, GREY, img);
			coord->x += lim;
			x++;
		}
		coord->x = 0;
		coord->y +=lim;
		y++;
	}
} 