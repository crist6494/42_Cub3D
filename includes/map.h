/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:40:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/23 18:13:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/MLX42.h"

#define WIDTH 700
#define HEIGHT 700

typedef struct s_point{
	int x0; 
	int y0;
	int x1;
	int y1;
}t_point;

void line(t_point *p, mlx_image_t *img);
void square_paint(float lim_y, float lim_x, mlx_image_t *img);

#endif