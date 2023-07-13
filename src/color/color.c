/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:25 by manujime          #+#    #+#             */
/*   Updated: 2023/07/13 18:11:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//slits the rgb string into individual components
//converts each component to an int and returns the color
int	ft_get_hex_color(char *rgb)
{	
	char	**rgb_split;
	int		r;
	int		g;
	int		b;
	int		a;

	a = 255;
	rgb_split = ft_split(rgb, ',');
	r = ft_atoi(rgb_split[0]);
	g = ft_atoi(rgb_split[1]);
	b = ft_atoi(rgb_split[2]);
	ft_free_char_matrix(rgb_split);
	return (r << 24 | g << 16 | b << 8 | a);
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