/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 20:19:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main()
{
	t_coord coord;
	t_map map;
	t_player player;
	t_game game;
	//atexit(ft_void);

	game.player = &player;
	game.map = &map;
	game.coord = &coord;
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game.mlx)
        error();
	mlx_set_window_limit(game.mlx, 1000, 1000, WIDTH, HEIGHT);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!game.img)
		error();
	char *line = "/Users/cmorales/42/Cub3D/assets/maps/map.cub";
	//init_player(&player, &game);
	init_map(&map, line);
	clear_map(&game);
	create_map(&game, &map, map.half_x, map.half_y);
	free_map(&map);
	//map_print(&game);
	//paint_map(&game, &map, &coord);
	//read_map(&map);
	//paint_player(&game, game.player);
	if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
        error();
	//mlx_resize_hook(game.mlx, &hook_screen, (void *)(&game));
	mlx_key_hook(game.mlx, &hook, (void *)(&game));
	//mlx_loop_hook(game.mlx, &move_hook, (void *)(&game));
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
} 