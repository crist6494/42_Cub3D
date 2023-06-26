/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:39:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/26 11:37:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void raycast_vertical(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitVertical)
{
	int		vertical_hit;
	float	y_intercept;
	float	x_intercept;
	t_coord step;
	
	vertical_hit = 0;
	x_intercept = floor(player->square->p_center->x / map->lim) * map->lim;
	if(ray->left == 0)
		x_intercept += map->lim;
		
	y_intercept = player->square->p_center->y;
	y_intercept += ((x_intercept - player->square->p_center->x) * tan(ray->rads_angle));
	
	step.x = map->lim;
	step.y = map->lim * (float)tan(ray->rads_angle);
	printf("\n");
	printf("P_x: %f\n", player->square->p_center->x);
	printf("P_y: %f\n", player->square->p_center->y);
	printf("Tangente: %f\n", (float)tan(ray->rads_angle));
	printf("Diferencia: %f\n", (float)(x_intercept - player->square->p_center->x));
	printf("y_intercept: %f\n", y_intercept);
	printf("x_intercept: %f\n", x_intercept);
	printf("step_x: %f\n", step.x);
	printf("step_y: %f\n", step.y);
	wallHitVertical->x = x_intercept;
	wallHitVertical->y = y_intercept;

	step.y = -step.y;
	if(ray->left == 1)
		step.x = -step.x;
	if((ray->down == 0 && step.y > 0) || (ray->down == 1 && step.y < 0))
		step.y = -step.y;

	while(vertical_hit == 0
		&&wallHitVertical->x < (float) map->len_x * map->width
		&&wallHitVertical->x > 1.0
		&&wallHitVertical->y > 1.0
		&&wallHitVertical->y < (float) map->len_y * map->height)
	{
		int box_x;
		int box_y;
		int box_x1;
		int box_y1;

		box_x = (int)wallHitVertical->x / (int)map->lim;
		box_y = (int)wallHitVertical->y / (int)map->lim;
		box_x1 = ((int)wallHitVertical->x -1) / (int)map->lim;
		box_y1 = ((int)wallHitVertical->y) / (int)map->lim;
		if((map->tour[box_y][box_x] == '1') || (ray->left == 1 && map->tour[box_y1][box_x1]))
		{
			//printf("Entra_v\n");
			vertical_hit = 1;
		}
		else
		{
			wallHitVertical->x += step.x;
			wallHitVertical->y += step.y;
		}	 
	}
}



/* static void	raycast_horizontal(t_map *map, t_player *player,
		t_point_f *wall_hit_horizontal, t_data_raycast *data)
{
	float		y_intercept;
	float		x_intercept;
	t_point_f	step;

	y_intercept
		= floor(player->pos_y / (float)map->height) * (float)map->height;
	if (data->abajo == 1)
		y_intercept += (float)map->height;
	x_intercept = player->pos_x;
	x_intercept += (y_intercept - player->pos_y) / tan(data->rads);
	step.y = map->height;
	step.x = ((float)((float)map->height) / tan(data->rads));
	wall_hit_horizontal->x = x_intercept;
	wall_hit_horizontal->y = y_intercept;
	step.x = -step.x;
	if (data->abajo == 0)
		step.y = -step.y;
	if (data->abajo == 1)
		step.x = -step.x;
	horizontal_ray_cast_loop(map, wall_hit_horizontal, data, &step);
}
void	horizontal_ray_cast_loop(t_map *map, t_point_f *wall_hit_horizontal,
		t_data_raycast *data, t_point_f *step)
{
	int	horizontal_hit;

	horizontal_hit = 0;
	while (horizontal_hit == 0
		&& wall_hit_horizontal->x < (float)(map->width * map->columns) && wall_hit_horizontal->x > 1.0 && wall_hit_horizontal->y > 1.0
		&& wall_hit_horizontal->y < (float)(map->rows * map->height))
	{
		if (map->map[(int)wall_hit_horizontal->y / map->height][(int)wall_hit_horizontal->x
			/ map->width] == '1' || (data->abajo == 0
			&& map->map[(int)(wall_hit_horizontal->y - 1)
			/ map->height][((int)wall_hit_horizontal->x) / map->width] == '1'))
			horizontal_hit = 1;
		else
		{
			wall_hit_horizontal->x += step->x;
			wall_hit_horizontal->y += step->y;
		}
	}
}



static void	raycast_vertical(t_map *map, t_player *player,
		t_point_f *wall_hit_vertical, t_data_raycast *data)
{
	float		y_intercept;
	float		x_intercept;
	t_point_f	step;
	printf("%d\n", map->width);
	x_intercept = floor(player->pos_x / (float)map->width) * (float)map->width;
	if (data->izquierda == 0)
		x_intercept += map->width;
		
	y_intercept = player->pos_y;
	y_intercept += ((float)(x_intercept - player->pos_x) * tan(data->rads));
	
	step.x = (float)map->width;
	step.y = ((float)((float)map->height) *tan(data->rads));
	
	wall_hit_vertical->y = y_intercept;
	wall_hit_vertical->x = x_intercept;
	
	step.y = -step.y;
	if (data->izquierda == 1)
		step.x = -step.x;
	if (data->izquierda == 0)
		step.y = -step.y;
	vertical_ray_cast_loop(map, wall_hit_vertical, data, &step);
}
void	vertical_ray_cast_loop(t_map *map, t_point_f *wall_hit_vertical,
		t_data_raycast *data, t_point_f *step)
{
	int	vertical_hit;
	printf("Row: %d\n", map->rows);
	printf("Colum: %d\n", map->columns);
	printf("Widht: %d\n", map->width);
	printf("Height: %d\n", map->height);
	vertical_hit = 0;
	while (vertical_hit == 0
		&& wall_hit_vertical->x < (float)(map->width * map->columns)
		&& wall_hit_vertical->x > 1.0 && wall_hit_vertical->y > 1.0
		&& wall_hit_vertical->y < (float)(map->rows * map->height))
	{
		if (map->map[(int)wall_hit_vertical->y
				/ map->height][(int)wall_hit_vertical->x / map->width] == '1'
			|| (data->izquierda == 1 && map->map[((int)wall_hit_vertical->y)
			/ map->height][(int)(wall_hit_vertical->x - 1)
			/ map->width] == '1'))
			vertical_hit = 1;
		else
		{
			wall_hit_vertical->x += step->x;
			wall_hit_vertical->y += step->y;
		}
	}
}
 */