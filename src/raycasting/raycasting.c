/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:56:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/21 23:32:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void init_ray(t_ray *data, float angle)
{
	data->wallHitHorizontal = malloc(sizeof(t_coord));
	//Sacamos direccion que se mueve el rayo
	data->down = 0;
	data->left = 0;
	data->rads_angle = grades_to_rad(angle);
	if(data->rads_angle > (float)0 && data->rads_angle < (float)M_PI)
		data->down = 1;
	if(data->rads_angle > (float)M_PI / 2 && data->rads_angle < 3 * (float)M_PI / 2)
		data->left = 1;
}

void raycast_horizonal(t_map *map, t_player *player, t_ray *ray)
{
	int		horizontal_hit;//Dice si hay una colision horizontal
	float	y_intercept;
	float	x_intercept;
	float	adyacente;
	t_coord step;
	//t_coord nextHorizontal;
	//(void)nextHorizontal;
	horizontal_hit = 0;
	//Calculamos primera interseccion si va haci abajo se suma una por el redondeo
	//Sacar la nueva altura restamos la posicion y2 - y1 y sabemos lo que mide y
	y_intercept = floor(player->square->p_center->y / map->lim) * map->lim;
	if(ray->down == 1)
		y_intercept += map->lim;
	adyacente = y_intercept - player->square->p_center->y;
	//Sacamos x con la tangete ya que sabemos "y" y la distancia se la sumo a x1
	x_intercept = player->square->p_center->x;
	x_intercept += (adyacente / tan(ray->rads_angle));

	//Calculamos distancia de cada paso
	step.y = map->lim;
	step.x = step.y / (float)tan(ray->rads_angle);
	ray->wallHitHorizontal->x = x_intercept;
	ray->wallHitHorizontal->y = y_intercept;
	//Si vamos hacia arriba invertimos direccion
	if(ray->down == 0)
		step.y = -step.y;
	//Coprobamos coherencia de la x
	if((ray->left == 1 && step.x > 0) || (ray->left == 0 && step.x < 0))
		step.x = -step.x;
		
	//nextHorizontal.x = step.x;
	//nextHorizontal.y = step.y;
	//Si va hacia arriba resta un pixel para forzar colision
	/* if(ray->down == 1)
		nextHorizontal.y--; */
	//Bucle buscar punto de colsion
	while(horizontal_hit == 0
		&&ray->wallHitHorizontal->x < (float) map->len_x * map->width
		&& ray->wallHitHorizontal->x > 1.0
		&& ray->wallHitHorizontal->y > 1.0
		&& ray->wallHitHorizontal->y < (float) map->len_y * map->height)
	{
		int box_y = (int)ray->wallHitHorizontal->y / (int)map->lim;
		int box_x = (int)ray->wallHitHorizontal->x / (int)map->lim;
		//int box_y1 = ((int)ray->wallHitHorizontal->y - 1) / (int)map->lim;
		//int box_x1 = ((int)ray->wallHitHorizontal->x - 1) / (int)map->lim;
		//Obtenemos casilla redondeada hacia abajo
		if((map->tour[box_y][box_x] == '1')
			/*|| (ray->down == 0 && map->tour[box_y1][box_x1] == '1')*/)
		{
			horizontal_hit = 1;
		}
		else
		{
			ray->wallHitHorizontal->x += step.x;
			ray->wallHitHorizontal->y += step.y;
		}	 
	}
}

void raycast(t_game *game, t_player *player, t_ray *ray)
{
	(void)game;
	init_ray(ray, player->angle);
	raycast_horizonal(game->map, player, ray);
	init_points(player->p_line, player->square->p_center, ray->wallHitHorizontal);//Iniciar linea
   	paint_line(player->p_line, game->img, RED);
}