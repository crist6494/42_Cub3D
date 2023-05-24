/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:32:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/24 21:13:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void read_map(t_map *map, char **stage)
{
	int y;
	
	y = 0;
	map->tour = malloc(sizeof(char *) * 5);
	while(y < 5)
	{
		int x;
		x = 0;
		map->tour[y] = malloc(sizeof(char) * 5);
		while(x < 5)
		{
			printf("aqui\n");
			map->tour[y][x] = (stage[y][x]);
			x++;	
		}
		y++;
	}
}

void map_print(t_map *map, char **stage)
{
	read_map(map, stage);
	int y = 0;
	while(y < 5)
	{
		int x;
		x = 0;
		while(x < 5)
		{
			printf("El valor de x es: %d", map->tour[y][x]);
		}
		y++;
	}
}