/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_paint_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:36:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 18:37:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	insert_paint_p(t_paint_p *c, int x, int y)
{
	c->x = x;
	c->y = y;
}

void	insert_coord(t_coord *c, float x, float y)
{
	c->x = x;
	c->y = y;
}

void	init_points(t_point *p, t_coord *c, t_coord *c1)
{
	p->x = c->x;
	p->y = c->y;
	p->x1 = c1->x;
	p->y1 = c1->y;
}
