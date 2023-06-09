/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:49:02 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 19:52:35 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_len_y(char *path)
{
	char *line;
	int fd;
	int y;
	
	y = 0;
	fd = open(path, O_RDONLY);
	if(fd == -1)
	{
		printf("No puede abrir ruta");
		return (-1);
	}
	line = get_next_line(fd);
	while(line != 0)
	{
		free(line);
		y++;
		line = get_next_line(fd);
		//printf("Longitud: %zu\n", ft_strlen(line));
	}
	close(fd);
	free(line);
	return (y);
}

int get_len_x(char *path)
{
	char *line;
	int fd;
	int x;
	int final_x;
	
	fd = open(path, O_RDONLY);
	if(fd == -1)
	{
		printf("No puede abrir ruta");
		return (-1);
	}
	line = get_next_line(fd);
	x = 0;
	final_x = 0;
	while(line != 0)
	{
		x = strlen(line);
		if(x > final_x)
			final_x = x;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (final_x);
}

char **alloc_map(t_map *map)
{
	char	**tour;
	unsigned int		y;

	y = 0;
	tour = ft_calloc(map->len_y + 1, sizeof(char *));
	while (y < map->len_y)
	{
		tour[y] = ft_calloc(map->len_x + 1, sizeof(char));
		y++;
	}
	return (tour);
}

void fill_map(t_map *map)
{
	unsigned int x;
	unsigned int y;
	
	y = 0;
	printf("%d\n", map->len_x);
	printf("%d\n", map->len_y);
	while(y < map->len_y)
	{
		x = 0;
		while(x < map->len_x)
		{
			map->tour[y][x] = ' ';
			x++;
		}
		y++;
	}
}

void	fill_values_map(t_map *map, char *path)
{
	char *line;
	int x;
	int y;
	int fd;

	y = 0;
	fd = open (path, O_RDONLY);
	if(fd == -1)
	{
		printf("No se puede abrir");
		return;
	}
	line = get_next_line(fd);
	while(line != 0)
	{
		x = 0;
		while(line[x] != '\0' && line[x] != '\n')
		{
			map->tour[y][x] = line[x];
			x++;
		}
		y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

void get_map(t_map *map, char *path_map)
{
	map->tour = alloc_map(map);
	fill_map(map);
	fill_values_map(map, path_map);
}

void init_map(t_map *map, char *path_map)
{
	map->len_x = get_len_x(path_map);
	map->len_y = get_len_y(path_map);
	get_map(map, path_map);
	map->lim = 40;
	map->map_width = map->len_x * map->lim; 
	map->map_height = map->len_y * map->lim;
	map->half_x = (WIDTH - map->map_width) / 2;
	map->half_y = (HEIGHT - map->map_height) / 2;
	map->m_coord = malloc(sizeof(t_coord));
}
