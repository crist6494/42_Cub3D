/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:17:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 21:43:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//Fuction when press SCAPE for finish the window and free all leaks
void	escape_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_free_char_matrix(game->comp->map);
		free_player(game->player);
		mlx_close_window(game->mlx);
		ft_exit_parse_error(game->comp);
		exit(1);
	}
}

//Fuction that allow resize the window to other size
void	hook_screen(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (width < 1800 || height < 1100)
		mlx_set_setting(MLX_STRETCH_IMAGE, true);//This resize when the window is small but play different
	mlx_delete_image(game->mlx, game->minimap->img);
	game->minimap->img = mlx_new_image(game->mlx, 331, 331);
	if (!game->minimap->img)
		error();
	if (mlx_image_to_window(game->mlx, game->minimap->img, 30, 30) < 0)
		error();
	repaint(game, game->player);
}

//Fuction to rotate the player with the cursor
void	cursor_hook(double xpos, double ypos, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	(void)ypos;
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_MIDDLE))
	{
		mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
		if (xpos - (WIDTH / 2) > 0)
			rotate(game, game->player, 1);
		else
			rotate(game, game->player, -1);
	}
	else
		mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
}

//The fuction that is in the loop and move and paint the game
void	move_hook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		player_advance(game, game->player, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		player_advance(game, game->player, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		player_lateral(game, game->player, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		player_lateral(game, game->player, 1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate(game, game->player, -1);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate(game, game->player, 1);
	repaint(game, game->player);
}
