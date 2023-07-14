/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 20:06:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_clean(t_game *game)
{
	free_player(game->player);
	ft_free_char_matrix(game->comp->map);
	mlx_close_window(game->mlx);
	ft_exit_parse_error(game->comp);
	exit(1);
}

void	init_game(t_game *game, char *path)
{
	t_minimap	minimap;

	game->minimap = &minimap;
	init_map(game, game->map, path);
	init_player(game->player, game, game->player->square);
	if (BONUS == 1)
		init_minimap(game, game->minimap, WIDTH, 30);
	repaint(game, game->player);
	mlx_key_hook(game->mlx, &escape_hook, (void *)(game));
	mlx_loop_hook(game->mlx, &move_hook, (void *)(game));
	if (BONUS == 1)
	{
		mlx_cursor_hook(game->mlx, &cursor_hook, (void *)(game));
		mlx_resize_hook(game->mlx, &hook_screen, (void *)(game));
	}
	mlx_loop(game->mlx);
}

void	init_window(t_game *game, char *path)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game->mlx)
		error();
	mlx_set_window_limit(game->mlx, 700, 700, WIDTH, HEIGHT);
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->map->img = game->img;
	if (!game->img)
		error();
	if (mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
		error();
	init_game(game, path);
	ft_clean(game);
	mlx_terminate(game->mlx);
}

//atexit(ft_void);
int	main(int ac, char **av)
{
	t_map		map;
	t_player	player;
	t_game		game;
	t_square	square;
	t_ray		ray;

	game.player = &player;
	game.map = &map;
	game.player->square = &square;
	game.ray = &ray;
	if (ac != 2 || !ft_file_check(av[1]))
		return (print_error(USAGE_MSG));
	ft_parse(&game, av[1]);
	init_window(&game, av[1]);
	return (EXIT_SUCCESS);
}
