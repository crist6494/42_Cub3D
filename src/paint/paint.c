/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/12 20:50:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img)
{
    float del_x;
    float del_y;
	float y;
	float x;
    
    del_y = lim + coord->y;
    del_x = lim + coord->x;
    y = coord->y;
	while(y <= del_y)
	{
        x = coord->x;
		while(x <= del_x)
		{
			mlx_put_pixel(img, (int)x, (int)y, color);
			x++;
		}
		y++;		
	}

}
static void draw_background(t_4square *background, mlx_image_t * img, int color);

void paint_ceil_floor(t_player *player, t_comp *comp)
{
    t_4square floor;
    t_4square ceil;

    // Calcula la mitad de la pantalla en el eje y
    int half_screen_y = player->screen_y / 2;

    // Pinta la mitad superior de la pantalla de un color
    insert_paint_p(&ceil.p0, 0 , 0);
    insert_paint_p(&ceil.p1, player->screen_x , 1);
    insert_paint_p(&ceil.p2, player->screen_x - 1 , half_screen_y);
    insert_paint_p(&ceil.p3, 1 , half_screen_y);
    draw_background(&ceil, player->img, comp->f_hex);

    // Pinta la mitad inferior de la pantalla de otro color
    insert_paint_p(&floor.p0, 1, half_screen_y);
    insert_paint_p(&floor.p1, player->screen_x - 1, half_screen_y);
    insert_paint_p(&floor.p2, player->screen_x - 1, player->screen_y - 1);
    insert_paint_p(&floor.p3, 1, player->screen_y - 1);
    draw_background(&floor, player->img, comp->c_hex);
}

static void draw_background(t_4square *background, mlx_image_t *img, int color)
{
    t_paint_p top;
    t_paint_p bottom;
    
    insert_paint_p(&top, background->p0.x, background->p0.y);
    insert_paint_p(&bottom, background->p2.x, background->p2.y);
    
    while (top.y <= bottom.y)
    {
        top.x = background->p0.x;
        while (top.x <= bottom.x)
        {
            mlx_put_pixel(img, top.x, top.y, color);
            top.x++;
        }
        top.y++;
    }
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t reversecolor(unsigned int color)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = color >> 24;
	green = color << 8 >> 24;
	blue = color << 16 >> 24;
	alpha = color << 24 >> 24;
	return (get_rgba(alpha, blue, green, red));
}
