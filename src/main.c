/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/03 18:37:14 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main()
{
	t_point p;
	t_coord coord;
	t_map map;
	t_player player;
	t_game game;
	(void)p;

	p.x0 = 0;
	p.y0 = 10;
	
	p.x1 = 10;
	p.y1 = 10;
	
	game.player = &player;
	game.map = &map;
	game.coord = &coord;
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game.mlx)
        error();
	mlx_set_window_limit(game.mlx, 800, 800, WIDTH, HEIGHT);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!game.img)
		error();
	paint_map(&game, &map, &coord);
	//paint_player(&coord, game.img);
	if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
        error();
	mlx_resize_hook(game.mlx, &hook_screen, (void *)(&game));
	mlx_key_hook(game.mlx, &hook, (void *)(&game));
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
} 
