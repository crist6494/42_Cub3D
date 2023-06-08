/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/08 17:32:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void insert_coord(t_coord *c, float x, float y)
{
    c->x = x;
    c->y = y;
}

void init_points(t_point *p, t_coord *c, float c_x1, float c_y1)
{
    p->x = c->x;
    p->y = c->y;
    p->x1 = c_x1;
    p->y1 = c_y1;
}

int	ft_sign(int x, int x1)
{
	if (x < x1)
		return (1);
	else
		return (-1);
}

void	paint_line(t_point *p, mlx_image_t *img)
{
	p->dx = fabsf(p->x1 - p->x);
	p->dy = -fabsf(p->y1 - p->y);
	p->err = p->dx + p->dy;
	while (1)
	{
		mlx_put_pixel(img, p->x, p->y, RED);
		if (p->x == p->x1 && p->y == p->y1)
			break ;
		p->e2 = 2 * p->err;
		if (p->e2 >= p->dy)
		{
			p->err += p->dy;
			p->x += ft_sign((int)p->x, (int)p->x1);
		}
		if (p->e2 <= p->dx)
		{
			p->err += p->dx;
			p->y += ft_sign((int)p->y, (int)p->y1);
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

