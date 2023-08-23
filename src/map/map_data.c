/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:25:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 11:53:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Function to get the angle character according to the direction
int	ft_get_player_angle(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N')
				return (270);
			if (map[y][x] == 'S')
				return (90);
			if (map[y][x] == 'W')
				return (180);
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (-1);
}

//Fuction to get the nº x of the map
int	ft_get_len_x(char **map)
{
	int	i;
	int	longest;

	i = 0;
	longest = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > (size_t)longest)
			longest = ft_strlen(map[i]);
		i++;
	}
	return (longest);
}

//Fuction to get the nº y of the map
int	ft_get_len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

//Fuction to get the coord of the character
t_coord	ft_get_player_pos(char **map)
{
	t_coord	begin;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				begin.x = x;
				begin.y = y;
			}
			x++;
		}
		y++;
	}
	return (begin);
}
