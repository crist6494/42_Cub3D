/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/03 11:34:28 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void line(t_map *map, mlx_image_t *img)
{
    // Variables para definir la dirección y la longitud de la línea
    int dx = map->x1 - map->x0;
    int dy = map->y1 - map->y0;
    int sx = 1;
    if (dx < 0) {
        sx = -1;
        dx = -dx;
    }
    int sy = 1;
    if (dy < 0) {
        sy = -1;
        dy = -dy;
    }
    int err = dx - dy;
    
    // Variables para trazar la línea punto por punto
    int x = map->x0;
    int y = map->y0;
    
    // Traza la línea punto por punto
    while (x != map->x1 || y != map->y1)
    {
        // Dibuja el punto actual
        mlx_put_pixel(img, x, y, 0xFF0000FF);
        
        // Calcula el error de posición y actualiza la posición del punto
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void square_paint(float lim_y, float lim_x, mlx_image_t *img)
{
	float y = 0;

	while(y <= lim_y)
	{
		float x = 0;
		while(x <= lim_x)
		{
			mlx_put_pixel(img, x, y, 0xFF0000FF);
			x++;
		}
		y++;		
	}
}