/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 21:37:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Paint a line with 2 t_coord 1 the start and the other the end with Bresenham

static void	paint_loop(t_point *p, mlx_image_t *img, int isSwaped,
				uint32_t color);

static int	sign(int d)
{
	int	s;

	if (d >= 0)
		s = 1;
	else
		s = -1;
	return (s);
}

static void	swap(float *dx, float *dy)
{
	float	aux;

	aux = *dx;
	*dx = *dy;
	*dy = aux;
}

void	paint_line(t_point *p, mlx_image_t *img, uint32_t color)
{
	int	is_swaped;

	p->dx = p->x1 - p->x;
	p->dy = p->y1 - p->y;
	p->sx = sign(p->dx);
	p->sy = sign(p->dy);
	is_swaped = 0;
	if (fabs(p->dy) > fabs(p->dx))
	{
		swap(&p->dx, &p->dy);
		is_swaped = 1;
	}
	mlx_put_pixel(img, p->x, p->y, color);
	paint_loop(p, img, is_swaped, color);
}

static void	paint_loop(t_point *p, mlx_image_t *img, int isSwaped,
		uint32_t color)
{
	int		i;
	float	err;

	err = 2 * (fabs(p->dy)) - fabs(p->dx);
	i = 0;
	while (i <= fabs(p->dx))
	{
		if (err < 0)
		{
			if (isSwaped == 0)
				p->x += p->sx;
			else
				p->y += p->sy;
			mlx_put_pixel(img, p->x, p->y, color);
			err += 2 * fabs(p->dy);
		}
		else
		{
			p->x += p->sx;
			p->y += p->sy;
			mlx_put_pixel(img, p->x, p->y, color);
			err += 2 * fabs(p->dy) - 2 * fabs(p->dx);
		}
		i++;
	}
}

/*void bresenham(float x1, float y1, float x2, float y2, mlx_image_t img)
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
} */