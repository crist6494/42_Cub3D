/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:17:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/31 19:04:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void hook(mlx_key_data_t keydata, void *param)
{
	t_game *game; 
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		exit(1);
	}
	/* if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("Hola\n"); */
		//game->player->image->instances[0].y -= 5;;
}


/* void move_hook(mlx_key_data_t keydata, void *param)
{
	t_player *player;

	player = param;

	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		player->image->instances[0].y -= 5;;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		player->image->instances[0].y += 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		player->image->instances[0].x -= 5;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		player->image->instances[0].x += 5;} */