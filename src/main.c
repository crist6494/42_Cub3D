/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/29 20:01:37 by cmorales         ###   ########.fr       */
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

	//coord.x = 350.0f;
	//coord.y = 350.0f;

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
	(void)stage;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		error();
	game.mlx = mlx;
	game.player = &player;
	create_map(&map, img, stage, &coord);
	paint_player(&coord, img);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();
	mlx_key_hook(mlx, &hook, (void *)(&game));
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}