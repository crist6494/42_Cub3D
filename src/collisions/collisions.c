/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:59:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/19 20:44:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void check_collision_vertical(t_map *map, t_player *player, float advance_x, float advance_y);
void check_collision_horizontal(t_map *map, t_player *player, float advance_x, float advance_y);
void check_collision_diagonal(t_map *map, t_player *player, float advance_x, float advance_y);

void check_collision(t_map *map, t_player *player, float advance_x, float advance_y)
{
	if((int)advance_x == 0 && (int)advance_y != 0)
		check_collision_vertical(map, player, advance_x, advance_y);
	else if((int)advance_x != 0 && (int)advance_y == 0)
		check_collision_horizontal(map, player, advance_x, advance_y);
	else if((int)advance_x != 0 && (int)advance_y != 0)
		check_collision_diagonal(map, player, advance_x, advance_y);
	//update_direction(player);//Actualizamos punto que movemos
}

/* 	printf("\n");
	printf("Avanza_x: %f\n", advance_x);
	printf("Avanza_y: %f\n", advance_y);
	printf("Ancho: %d\n", (int)map->width);
	printf("Alto: %d\n", (int)map->height);
	printf("P_center_x: %d\n", (int)player->square->p_center->x);
	printf("P_center_y: %d\n", (int)player->square->p_center->y); */
	/* printf("aux_x:%d\n", (int)aux_x);
	printf("aux_y:%d\n", (int)aux_y);
	printf("Pos:%d\n", (int)aux_x / (int)map->lim);
	printf("Pos:%d\n", (int)aux_y / (int)map->lim); */


void check_collision_vertical(t_map *map, t_player *player, float advance_x, float advance_y)
{
	float py;

	py = 0;
	if(advance_y < 0)
	{
		py = check_up_collision(player, map, advance_x, advance_y);
	}
	else
		py = check_down_collision(player, map, advance_x, advance_y);
	player->square->p_center->y = py;
}


void check_collision_horizontal(t_map *map, t_player *player, float advance_x, float advance_y)
{
	float px;
	px = 0;
	if(advance_x < 0)
		px = check_left_collision(player, map, advance_x, advance_y);
	else
		px = check_right_collision(player, map, advance_x, advance_y);
	player->square->p_center->x = px;
}

void check_collision_diagonal(t_map *map, t_player *player, float advance_x, float advance_y)
{
	if (advance_x < 0 && advance_y < 0)
	{
		player->square->p_center->x = check_left_collision(player, map, advance_x, advance_y);
		player->square->p_center->y = check_up_collision(player, map, advance_x, advance_y);
	}
	else if (advance_x > 0 && advance_y < 0)
	{
		player->square->p_center->x = check_right_collision(player, map, advance_x, advance_y);
		player->square->p_center->y = check_up_collision(player, map, advance_x, advance_y);
	}
	else if (advance_x > 0 && advance_y > 0)
	{
		player->square->p_center->x = check_right_collision(player, map, advance_x, advance_y);
		player->square->p_center->y = check_down_collision(player, map, advance_x, advance_y);
	}
	else if (advance_x < 0 && advance_y > 0)
	{
		player->square->p_center->x = check_left_collision(player, map, advance_x, advance_y);
		player->square->p_center->y = check_down_collision(player, map, advance_x, advance_y);
	}
}
