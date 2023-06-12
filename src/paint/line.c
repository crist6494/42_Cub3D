/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:58:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/12 20:27:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


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
