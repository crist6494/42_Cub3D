/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/31 20:47:13 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void init_map(t_map *map)
{
	map->len_x = 7; 
	map->len_y = 7;
}

static void read_map(t_map *map, char stage[7][7])
{
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

void create_map(t_map *map, mlx_image_t *img, char stage[7][7], t_coord *coord)
{
	read_map(map, stage);
	unsigned int y;
	float lim = 20;
	
	int map_width = map->len_x * lim;
	int map_height = map->len_y * lim; 
	//coord->x = (CANVAS_WIDTH - map_width) / 2;
	//coord->y = (CANVAS_HEIGHT - map_height) / 2; 
	//float c_y = (CANVAS_HEIGHT - map_height) / 2; 
	//float c_x = (CANVAS_WIDTH - map_width) / 2;
	float aux_x;
	(void)aux_x;
	
	printf("El alto mapa es: %d\n", map_height);
	printf("El ancho mapa es: %d\n", map_width);
	insert_coord(coord, 1 , 1);
	aux_x = 1;

	y = 0;
	while(y < map->len_y)
	{
		unsigned int x;
		x = 0;
		coord->x = aux_x;
		while(x < map->len_x)
		{
			if(map->tour[y][x] == '1')
				square_paint(coord, lim, BLACK, img);
			else
				square_paint(coord, lim, GREY, img);
			coord->x += lim;
			x++;
		}
		coord->x = 0;
		coord->y +=lim;
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