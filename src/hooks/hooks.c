/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:17:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/05 20:56:19 by cmorales         ###   ########.fr       */
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

void hook_screen(int32_t width, int32_t height, void* param)
{
	t_game *game;
	game =(t_game *) param;
	(void)height;
	(void)width;

	//printf("width: %d\n", width);
	//printf("height: %d\n", height);
	clear_map(game);
	//create_map(game, game->coord, (50), ((width - game->map->map_width) - 50));
	create_map(game, game->coord, (height - game->map->map_width) / 2, (width - game->map->map_width) / 2);
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