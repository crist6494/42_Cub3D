/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/01 20:38:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void locate_screen(int32_t width, int32_t height, void* param)
{
	t_game *game;
	game =(t_game *) param;
	(void)height;

	//printf("width: %d\n", width);
	//printf("height: %d\n", height);
	clear_map(game, game->n_map);
	create_map(game, game->coord, game->n_map, (50), ((width - game->map->map_width) - 50));
}

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
	game.n_map = malloc(sizeof(char *) * 7);
	int x;
	int y = 0;
	while(y < 7)
	{
		game.n_map[y] = malloc(sizeof(char) * 7);
		y++;
	}
	y = 0;
	while(y < 7)
	{
		x = 0;
		while(x < 7)
		{
			game.n_map[y][x] = stage[y][x];
			x++;
		}
		game.n_map[y][x] = '\0';
		y++;
	}
	
	//map_print(&game);
	game.player = &player;
	game.map = &map;
	game.coord = &coord;
	(void)stage;
	game.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game.mlx)
        error();
	mlx_set_window_limit(game.mlx, 500, 500, WIDTH, HEIGHT);
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (!game.img)
		error();
	init_map(&map);
	clear_map(&game, game.n_map);
	create_map(&game, &coord, game.n_map, 50, (WIDTH - game.map->map_width) - 50);
	//paint_player(&coord, game.img);
	if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
        error();
	mlx_resize_hook(game.mlx, &locate_screen, (void *)(&game));
	mlx_key_hook(game.mlx, &hook, (void *)(&game));
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
} 
