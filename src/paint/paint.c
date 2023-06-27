/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:30:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/27 21:00:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void insert_coord(t_coord *c, float x, float y)
{
    c->x = x;
    c->y = y;
}

void insert_paint_p(t_paint_p *c, int x, int32_t y)
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
void draw_background(t_4square *background, mlx_image_t * img, int color, int sig);

void paint_ceil_floor(t_player *player)
{
    t_4square floor;
    t_4square ceil;

    insert_paint_p(&ceil.p0, 1 , 1);
    insert_paint_p(&ceil.p1, player->screen_x - 1 , 1);
    insert_paint_p(&ceil.p2, player->screen_x - 1 , player->screen_y / 2);
    insert_paint_p(&ceil.p3, 1 , player->screen_y / 2);
    
    insert_paint_p(&floor.p0, 1, player->screen_y / 2);
    insert_paint_p(&floor.p1, player->screen_x - 1, player->screen_y / 2);
    insert_paint_p(&floor.p2, player->screen_x - 1, player->screen_y - 1);
    insert_paint_p(&floor.p2, 1, player->screen_y - 1);
    draw_background(&ceil, player->img, BLUE, 0);
    draw_background(&floor, player->img, GREEN, 1);
}

void draw_background(t_4square *background, mlx_image_t * img, int color, int sig)
{
    t_paint_p top;
    t_paint_p bottom;
    
    insert_paint_p(&top, background->p0.x, background->p0.y);
    if(sig == 0)
	    insert_paint_p(&bottom, background->p2.x, background->p2.y);
    if(sig == 1)
	    insert_paint_p(&bottom, background->p3.x, background->p3.y);
	while (top.y < bottom.y)
	{
		top.x = background->p0.x;
		while (top.x < bottom.x)
		{
			mlx_put_pixel(img, top.x, top.y, color);
			top.x++;
		}
		top.y++;
	}
}

