/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:40:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/25 00:16:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "libft.h"
#include "MLX42/MLX42.h"

#define WIDTH 700
#define HEIGHT 700

typedef struct s_point{
	int x0; 
	int y0;
	int x1;
	int y1;
	int ix;
	int iy;
	int err;
	int dy;
	int dx;
	int x;
	int y;
}t_point;

typedef struct s_coord{
	float x;
	float y;
}t_coord;

typedef struct s_map{
	char **tour;
}t_map;

void line(t_point *p, mlx_image_t *img);
void square_paint(t_coord *coord, float lim_y, float lim_x, mlx_image_t *img);
void map_print(t_map *map, char stage[5][5]);

#endif