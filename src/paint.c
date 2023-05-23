/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/23 21:03:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void line(t_point *p, mlx_image_t *img)
{
    // Variables para definir la dirección y la longitud de la línea
    int dx = p->x1 - p->x0;
    int dy = p->y1 - p->y0;
    //Variables incremento
    int sx = 1;
    int sy = 1; 
    
    if (dx < 0) {
        sx = -1;
        dx = -dx;
    }
    if (dy < 0) {
        sy = -1;
        dy = -dy;
    }
    int err = dx - dy;
    
    // Variables para trazar la línea punto por punto
    int x = p->x0;
    int y = p->y0;
    
    // Traza la línea punto por punto
    while (x != p->x1 || y != p->y1)
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