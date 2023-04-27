/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/27 20:51:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void line(t_map *map, mlx_image_t *img)
{
    // Variables para definir la dirección y la longitud de la línea
    int dx = map->x1 - map->x0;
    int dy = map->y1 - map->y0;
    int sx = 1;
    if (dx < 0) {
        sx = -1;
        dx = -dx;
    }
    int sy = 1;
    if (dy < 0) {
        sy = -1;
        dy = -dy;
    }
    int err = dx - dy;
    
    // Variables para trazar la línea punto por punto
    int x = map->x0;
    int y = map->y0;
    
    // Traza la línea punto por punto
    while (x != map->x1 || y != map->y1)
    {
        // Dibuja el punto actual
        mlx_put_pixel(img, x, y, 0xFF0000FF);
        
        // Calcula el error de posición y actualiza la posición del punto
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
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
	t_map map;

	map.x0 = 10;
	map.y0 = 10;
	
	map.x1 = 110;
	map.y1 = 210;
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, 600, 600);
	if (!img)
		error();
	line(&map, img);
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_key_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}