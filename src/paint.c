/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/24 20:42:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void init_line(t_point *p)
{
    // Variables para definir la dirección y la longitud de la línea
    p->dx = p->x1 - p->x0;
    p->dy = p->y1 - p->y0;
    if (p->dx < 0) 
    {
        p->ix = -1;
        p->dx = -(p->dx);
    }
    if (p->dy < 0) {
        p->iy = -1;
        p->dy = -(p->dy);
    }
    //Variables incremento
    p->ix = 1;
    p->iy = 1;
    //Error de decision
    p->err = (p->dx - p->dy);
    // Variables para trazar la línea punto por punto
    p->x = p->x0;
    p->y = p->y0;
}

void line(t_point *p, mlx_image_t *img)
{
    init_line(p);
    while (p->x != p->x1 || p->y != p->y1)
    {
        int e2;
        mlx_put_pixel(img, p->x, p->y, 0xFF0000FF);
        e2 = p->err * 2;
        if (e2 > -(p->dy))  
        {
            p->err -= p->dy;
            p->x += p->ix;
        }
        if (e2 < p->dx)
        {
            p->err += p->dx;
            p->y += p->iy;
        }
    }
}

void square_paint(t_coord *coord, float lim_y, float lim_x, mlx_image_t *img)
{
    float del_x;
    float del_y;
	float y;
    
    y = coord->y;
    del_y = lim_y + coord->y;
    del_x = lim_x + coord->x;
	while(y <= del_y)
	{
		float x = coord->x;
		while(x <= del_x)
		{
			mlx_put_pixel(img, (int)x, (int)y, 0xFF0000FF);
			x++;
		}
		y++;		
	}
}