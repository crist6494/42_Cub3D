/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:05:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 20:08:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void ft_void()
{
	system("leaks -q Cub3D");
}

void free_map(t_map *map)
{
	unsigned int y;
	y = 0;
	while(y < map->len_y)
	{
		free(map->tour[y]);
		y++;
	}
	free(map->tour);
	free(map->m_coord);
}