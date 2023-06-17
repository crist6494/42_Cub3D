/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:59:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/17 22:59:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_collision_vertical(t_map *map, t_player *player, float advance_x, float advance_y);
int check_collision_horizontal(t_map *map, t_player *player, float advance_x, float advance_y);

void check_collision(t_map *map, t_player *player, float advance_x, float advance_y)
{
	(void)player;
	(void)map;
	if((int)advance_x == 0 && (int)advance_y != 0)
	{
		if(check_collision_vertical(map, player, advance_x, advance_y) == -1)
			return ;
	}
	else if((int)advance_x != 0 && (int)advance_y == 0)
	{
		if(check_collision_horizontal(map, player, advance_x, advance_y) == -1)
			return ;
	}
	player->square->p_center->x += advance_x;
	player->square->p_center->y += advance_y;
	update_direction(player);//Actualizamos punto que movemos
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


int check_left_down_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_left_down->x + advance_x;
	aux_y = player->square->p_left_down->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
	{
		printf("Entra izquierda abajo\n");
		return (-1);
	}
	return (0);
}

int check_right_down_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_right_down->x + advance_x;
	aux_y = player->square->p_right_down->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
	{
		printf("Entra derecha abajo\n");
		return (-1);
	}
	return (0);
}




int check_left_up_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_left_up->x + advance_x;
	aux_y = player->square->p_left_up->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
	{
		printf("Entra izquierda arriba\n");
		return (-1);
	}
	return (0);
}


int check_right_up_p(t_player * player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	float aux_y;

	aux_x = player->square->p_right_up->x + advance_x;
	aux_y = player->square->p_right_up->y + advance_y;
	if(map->tour[(int)aux_y / (int)map->lim][(int)aux_x / (int)map->lim] == '1')
	{
		printf("Entra derecha arriba\n");
		return (-1);
	}
	return (0);
}


int check_collision_vertical(t_map *map, t_player *player, float advance_x, float advance_y)
{
	//float aux_x;
	//float aux_y;

	//aux_x = player->square->p_center->x + advance_x + (player->tam / 2);
	//aux_y = player->square->p_center->y + advance_y + (player->tam / 2);
	if(check_right_down_p(player, map, advance_x, advance_y) == -1
		&&check_left_down_p(player, map, advance_x, advance_y) == -1)
	{
		printf("Entra aqui\n");
		return (-1);
	}
	else if(check_right_up_p(player, map, advance_x, advance_y) == -1
		&&check_left_up_p(player, map, advance_x, advance_y) == -1)
	{
		printf("\n");
		printf("Entra aqui\n");
		return (-1);
	}

	return (0);
}


int check_collision_horizontal(t_map *map, t_player *player, float advance_x, float advance_y)
{
	//float aux_x;
	//float aux_y;

	//aux_x = player->square->p_center->x + advance_x + (player->tam / 2);
	//aux_y = player->square->p_center->y + advance_y + (player->tam / 2);
	if(check_right_up_p(player, map, advance_x, advance_y) == -1
		&&check_right_down_p(player, map, advance_x, advance_y) == -1)
	{
		printf("Entra aqui\n");
		return (-1);
	}
	else if(check_left_up_p(player, map, advance_x, advance_y) == -1
		&&check_left_down_p(player, map, advance_x, advance_y) == -1)
	{
		printf("\n");
		printf("Entra aqui\n");
		return (-1);
	}

	return (0);
}