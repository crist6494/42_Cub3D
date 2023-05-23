/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/23 18:13:39 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

//void print_direct_lightning()

void hook(mlx_key_data_t keydata, void *param)
{
	mlx_t *cast = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(cast);
		exit(1);
	}
} 

int	main()
{
	t_point p;

	p.x0 = 10;
	p.y0 = 10;
	
	p.x1 = 10;
	p.y1 = 210;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, 600, 600);
	if (!img)
		error();
	line(&p, img);
    square_paint(10, 10, img);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_key_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}