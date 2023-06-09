/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:25:01 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 19:46:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void map_print(t_game *game)
{
	unsigned int y;
	y = 0;
	while(y < game->map->len_y)
	{
		unsigned int x;
		x = 0;
		while(x < game->map->len_x)
		{
			//printf("El valor de x es: %c\n", game->map->tour[y][x]);
			x++;
		}
		printf("El valor de y es: %s\n", game->map->tour[y]);
		y++;
	}
}

void	clear_map(t_game *game)
{
	unsigned int y;
	unsigned int x;
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			mlx_put_pixel(game->img, x, y, 0x4a4747FF);
			x++;
		}
		y++;
	}
}