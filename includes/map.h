/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:40:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/25 20:31:47 by cmorales         ###   ########.fr       */
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

#define RED 0xFF0000FF
#define GREY 0x808080FF
#define BLACK 0x000000FF

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
	int len_x;
	int len_y;
	char **tour;
}t_map;

void line(t_point *p, mlx_image_t *img);
void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);
void map_print(t_map *map, char stage[7][7]);
void create_map(t_map *map, mlx_image_t *img, char stage[7][7], t_coord *coord);

#endif