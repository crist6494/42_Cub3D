/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/29 20:01:02 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "libft.h"
#include "MLX42/MLX42.h"
#include "macros.h"

/* ---------------------------------------------------------------------------*
	-------------------------------STRUCTURES---------------------------------
*--------------------------------------------------------------------------- */

typedef struct s_player
{
	mlx_image_t *image;	
}t_player;

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

typedef struct s_game
{
	mlx_t	*mlx;
	t_player *player;	
}t_game;

/* ---------------------------------------------------------------------------*
	-------------------------------FUCTIONS---------------------------------
*--------------------------------------------------------------------------- */

void line(t_point *p, mlx_image_t *img);
void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);

void map_print(t_map *map, char stage[7][7]);
void create_map(t_map *map, mlx_image_t *img, char stage[7][7], t_coord *coord);

void hook(mlx_key_data_t keydata, void *param);

void paint_player(t_coord *coord, mlx_image_t *img);


void move_hook(mlx_key_data_t keydata, void *param);

void error(void);

# endif