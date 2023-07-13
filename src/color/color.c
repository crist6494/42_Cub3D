/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:30:25 by manujime          #+#    #+#             */
/*   Updated: 2023/07/13 16:48:52 by manujime         ###   ########.fr       */
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
