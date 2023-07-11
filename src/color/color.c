/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:25 by manujime          #+#    #+#             */
/*   Updated: 2023/07/11 17:55:29 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_getr(int color)
{
	return ((color >> 16) & 0xFF);
}

int	ft_getg(int color)
{
	return ((color >> 8) & 0xFF);
}

int	ft_getb(int color)
{
	return (color & 0xFF);
}

int	ft_rgbtoi(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	ft_get_hex_color(char *rgb)
{
	char	**rgb_split;
	int		r;
	int		g;
	int		b;

	rgb_split = ft_split(rgb, ',');
	r = ft_atoi(rgb_split[0]);
	g = ft_atoi(rgb_split[1]);
	b = ft_atoi(rgb_split[2]);
	return (ft_rgbtoi(r, g, b) & 0x00FFFFFF);
}
