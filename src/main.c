/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/01 11:56:48 by cmorales         ###   ########.fr       */
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
	(void)map;
	(void)coord;
	(void)p;

	p.x0 = 0;
	p.y0 = 10;
	
	p.x1 = 10;
	p.y1 = 10;

	char stage[7][7] = 
	{
		{'1', '1', '1', '1', '1', '1','1'},
        {'1', '0', '0', '0', '0', '0','1'},
        {'1', '0', '0', '0', '0', '0','1'},
        {'1', '0', '0', '1', '1', '0','1'},
        {'1', '0', '0', '1', '0', '0','1'},
        {'1', '0', '0', '0', '0', '0','1'},
        {'1', '1', '1', '1', '1', '1','1'},
	};  
	game.player = &player;
	game.map = &map;
	(void)stage;
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game.mlx)
        error();
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!game.img)
		error();
	init_map(&map);
	clear_map(&game, stage);
	create_map(&game, &coord, stage, map.half_y, map.half_x);
	//paint_player(&coord, game.img);
	if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
        error();
	mlx_key_hook(game.mlx, &hook, (void *)(&game));
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
} 
