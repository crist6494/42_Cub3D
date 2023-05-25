/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/25 00:16:44 by cmorales         ###   ########.fr       */
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
	t_coord coord;
	t_map map;
	(void)map;
	(void)coord;
	(void)p;

	p.x0 = 0;
	p.y0 = 10;
	
	p.x1 = 10;
	p.y1 = 10;

	coord.x = 350.0f;
	coord.y = 350.0f;

	char stage[5][5] = 
	{
		{'1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1'}
	};  
	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, 600, 600);
	if (!img)
		error();
	//line(&p, img);
    //square_paint(&coord,5, 5, img);
	//char **ptr_stage = (char**)stage;
	//printf("El stage: %c\n", ptr_stage[1][2]);
	map_print(&map, stage);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_key_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}