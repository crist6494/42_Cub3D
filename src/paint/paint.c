/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/13 21:04:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void insert_coord(t_coord *c, float x, float y)
{
    c->x = x;
    c->y = y;
}

void init_points(t_point *p, t_coord *c, t_coord *c1)
{
    p->x = c->x;
    p->y = c->y;
    p->x1 = c1->x;
    p->y1 = c1->y;
}

int	ft_sign(int x, int x1)
{
	if (x < x1)
		return (1);
	else
		return (-1);
}

/* void	paint_line(t_point *p, mlx_image_t *img)
{
	p->dx = fabsf(p->x1 - p->x);
	p->dy = -fabsf(p->y1 - p->y);
	p->err = p->dx + p->dy;

	while (1)
	{
		mlx_put_pixel(img, p->x, p->y, RED);
		if ((int)p->x == (int)p->x1 && (int)p->y == (int)p->y1)
			break ;
		p->e2 = 2 * p->err;
		if (p->e2 >= p->dy)
		{
			p->err += p->dy;
			p->x += ft_sign((int)p->x, (int)p->x1);
		}
		else if(p->e2 <= p->dx)
		{
			p->err += p->dx;
			p->y += ft_sign((int)p->y, (int)p->y1);
		}
		//printf("p->x1: %d, p->y1: %d\n", (int)p->x1, (int)p->y1);
		//printf("p->x: %d, p->y: %d\n", (int)p->x, (int)p->y);
	} 
}*/

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

 void bresenham(float x1, float y1, float x2, float y2, mlx_image_t img)
{
    // Find Delta
    float dx = x2-x1;
    float dy = y2-y1;

    // Find Signs
    int sx = (dx>=0) ? 1 : (-1);
    int sy = (dy>=0) ? 1 : (-1);

    // Get Initial Points
    float x = x1;
    float y = y1;

    // Flag to check if swapping happens
    int isSwaped = 0;

    // Swap if needed
    if(fabs(dy) > fabs(dx))
    {
        // swap dx and dy
        float tdx = dx;
        dx =dy;
        dy = tdx;

        isSwaped = 1;
    }

    // Decision parameter
    float p = 2*(fabs(dy)) - fabs(dx);

    //Print Initial Point
    mlx_put_pixel(&img, x, y, RED);

    // Loop for dx times
    for(int i = 0; i<= fabs(dx);i++)
    {
        // Depending on decision parameter
        if(p < 0)
        {
            if(isSwaped == 0){
                x = x + sx;
                mlx_put_pixel(&img, x, y, RED);
            }
            else{
                y = y+sy;
                mlx_put_pixel(&img, x, y, RED);
            }
            p = p + 2*fabs(dy);
        }
        else
        {
            x = x+sx;
            y = y+sy;
            mlx_put_pixel(&img, x, y, RED);
            p = p + 2*fabs(dy) - 2*fabs(dx);
        }
    }
} 
