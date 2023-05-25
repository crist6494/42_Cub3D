/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/25 00:27:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void read_map(t_map *map, char stage[5][5], int col, int row)
{
	int y;
	
	y = 0;
	map->tour = malloc(sizeof(char *) * col);
	if(!map->tour)
	{
		printf("Can't asign memory in tour char **\n");
		return ;
	}
	while(y < col)
	{
		int x;
		x = 0;
		map->tour[y] = malloc(sizeof(char) * row);
		if(!map->tour[y])
		{
			printf("Can't asign memory in tour char\n");
			return ;
		}
		while(x < row)
		{
			map->tour[y][x] = (stage[y][x]);
			x++;	
		}
		map->tour[y][x] = '\0';
		y++;
	}
}

void map_print(t_map *map, char stage[5][5])
{
	int y;
	int col;
	int row;

	col = 5; 
	row = 5;
	read_map(map, stage, col, row);
	y = 0;
	while(y < col)
	{
		int x;
		x = 0;
		while(x < row)
		{
			printf("El valor de x es: %c\n", map->tour[y][x]);
			x++;
		}

		printf("El valor de y es: %s\n", map->tour[y]);
		y++;
	}
}