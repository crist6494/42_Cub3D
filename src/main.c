/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/30 12:16:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "cub3D.h"

/* int	main()
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
} */

#include "MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>

void hook(mlx_key_data_t keydata, void *param)
{
	
	mlx_t *mlx;

	mlx = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(mlx);
		exit(1);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("Hola\n");
		//game->player->image->instances[0].y -= 5;;
}

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

void ft_randomize(void* param)
{
	(void)param;
	for (int32_t i = 0; i < 40; ++i)
	{
		for (int32_t y = 0; y < 40; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

int main()
{
	mlx_t* mlx = mlx_init(800, 800, "MLX42", true);
	if (!mlx)
        return (-1);
	mlx_image_t* img = mlx_new_image(mlx, 100, 800);	
	if (!img)
		return (-1);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        return (-1);
		
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_key_hook(mlx, &hook, mlx);
	mlx_loop_hook(mlx, &ft_hook, mlx);
	mlx_loop_hook(mlx, &ft_randomize, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}