/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/07 20:50:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void insert_coord(t_coord *c, float y, float x)
{
    c->y = y;
    c->x = x;
}

void init_points(t_point *p, t_coord *c, float c_y1, float c_x1)
{
    p->x0 = c->x;
    p->y0 = c->y;
    p->x1 = c_x1;
    p->y1 = c_y1;
}

static void init_line(t_point *p)
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
    p->iy = -1; 
    //Error de decision
    p->err = (p->dx - p->dy);
    // Variables para trazar la línea punto por punto
    p->x = p->x0;
    p->y = p->y0;
}

void paint_line(t_point *p, mlx_image_t *img)
{
    init_line(p);
    while (p->x != (int)p->x1 || p->y != (int)p->y1)
    {
        int e2;
        //printf("Coord x: %d\n", p->x);
        //printf("Coord y: %d\n", p->y);
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

void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img)
{
    float del_x;
    float del_y;
	float y;
    
    del_y = lim + coord->y;
    del_x = lim + coord->x;
    y = coord->y;
	while(y <= del_y)
	{
		float x;
        x = coord->x;
		while(x <= del_x)
		{
			mlx_put_pixel(img, (int)x, (int)y, color);
			x++;
		}
		y++;		
	}
}

