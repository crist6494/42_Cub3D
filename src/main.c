/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/11 13:56:13 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_window(t_game *game, char *path)
{
	(void)path;
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	//game->mlx = mlx_init(LINUX_WIDTH, LINUX_HEIGHT, "MLX42", true);
	if (!game->mlx)
        error();
	mlx_set_window_limit(game->mlx, 1000, 1000, WIDTH, HEIGHT);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->map->img = game->img;
	if (!game->img)
		error();
	//paint_map(game, game->map, path);
	clear_map(game->map);
	paint_player(game, game->player);
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
        error();
	init_map(game->map, path);
	mlx_key_hook(game->mlx, &hook, (void *)(game));
	//mlx_loop_hook(game->mlx, &move_hook, (void *)(&game));
	//mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game->img);
	mlx_terminate(game->mlx);
}


int	main(int ac, char **av)
{
	//atexit(ft_void);
	t_map map;
	t_player player;
	t_game game;

	game.player = &player;
	game.map = &map;
	if(ac == 3)
		return(print_error(USAGE_MSG));
	init_window(&game, av[1]);
	return (EXIT_SUCCESS);
} 