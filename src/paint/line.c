/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/13 21:09:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* int sx, sy;
if (dx >= 0) {
  sx = 1;
} else {
  sx = -1;
}

if (dy >= 0) {
  sy = 1;
} else {
  sy = -1;
} */

void loop_paint(t_point *p, mlx_image_t *img, int isSwaped);

int sign(int d)
{
    int s;
    
    if(d >= 0)
        s = 1;
    else
        s = -1;
    return (s);    
}


void swap(float dx, float dy)
{
    float aux;

    aux = dx;
    dx = dy;
    dy = aux;
}

void paint_line(t_point *p, t_coord *c, t_coord *c1, mlx_image_t *img)
{
    (void)c;
    (void)c1;
    int isSwaped;

    printf("%f\n", p->x);
    printf("%f\n", p->y);
    printf("%f\n", p->x1);
    printf("%f\n", p->y1);
    
    p->dx = p->x1 - p->x;
    p->dy = p->y1 - p->y;
    p->sx = sign(p->dx);
    p->sy = sign(p->dy);
    printf("%f\n", p->dx);
    printf("%f\n", p->dy);
    printf("%d\n", p->sx);
    printf("%d\n", p->sy);
    isSwaped = 0;
    if(fabs(p->dy) > fabs(p->dx))
    {
        swap(p->dx, p->dy);
        isSwaped = 1;
    }
    mlx_put_pixel(img, p->x, p->y, RED);
    loop_paint(p, img, isSwaped);
} 

void loop_paint(t_point *p, mlx_image_t *img, int isSwaped)
{
    float err;
    int i;

    float x = p->x;
    float y = p->y;

    i = 0;
    err = 2 * (fabs(p->dy)) - fabs(p->dx);
    while(i <= fabs(p->dx))
    {
         if(err < 0)
        {
            if(isSwaped == 0){
                x += p->sx;
                mlx_put_pixel(img, x, y, RED);
            }
            else{
                p->y += p->sy;
                mlx_put_pixel(img, x, y, RED);
            }
            err += 2 * fabs(p->dy);
        }
        else
        {
            x += p->sx;
            y += p->sy;
            mlx_put_pixel(img, x, y, RED);
            err += 2 * fabs(p->dy) - 2 * fabs(p->dx);
        }
        i++;
    }
}


