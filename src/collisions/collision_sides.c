/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:22:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/20 17:34:18 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float check_up_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_y;
	//int aux_advance_y;
	
	aux_y = player->square->p_center->y;
	if(check_right_up_p(player, map, advance_x, advance_y) == 0
		&&check_left_up_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		/* printf("Aux: %f\n", (float)aux_y);
		printf("Advace y: %f\n", advance_y);
		printf("Map: %d\n", map->height);
		aux_advance_y = (((int)player->square->p_center->y - (player->tam / 2)) % (int)map->height);
		printf("Aux_advance: %f\n", (float)aux_advance_y);
		printf("Tamaño: %d\n", player->tam / 2);
		if((float)aux_advance_y <= (-1.0 * advance_y) && aux_advance_y != 0)
		{
			printf("Entraaaa\n");
			aux_y -= (float)aux_advance_y;
		}
		else  */if(check_right_up_p(player, map, 0, advance_y) == 0
			&&check_left_up_p(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}  
	return (aux_y);
}

float check_down_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_y;
	//int aux_advance_y;

	aux_y = player->square->p_center->y;
	if(check_right_down_p(player, map, advance_x, advance_y) == 0
		&&check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		/* aux_advance_y = (int)map->height - (((int)player->square->p_center->y + (player->tam / 2)) % (int)map->height);
		if(aux_advance_y <= (player->tam / 2) && (float)aux_advance_y <= advance_y && aux_advance_y != 0)
			aux_y += (float)aux_advance_y;
		else  */if(check_right_down_p(player, map, 0, advance_y) == 0
			&&check_left_down_p(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}

float check_left_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	//int aux_advance_x;

	aux_x = player->square->p_center->x;
	if(check_left_up_p(player, map, advance_x, advance_y) == 0
		&&check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else{
		/* aux_advance_x = (((int)player->square->p_center->x - player->tam / 2) % (int)map->width);
		if(aux_advance_x <= player->tam / 2 && (float)aux_advance_x <= (1.0 * advance_x) && aux_advance_x != 0)
			aux_x -= (float)aux_advance_x;
		else  */if(check_left_up_p(player, map, advance_x, 0) == 0
			&&check_left_down_p(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}

float check_right_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	//int aux_advance_x;

	aux_x = player->square->p_center->x;
	if(check_right_up_p(player, map, advance_x, advance_y) == 0
		&&check_right_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		/* aux_advance_x = (int)map->width - (((int)player->square->p_center->x + (player->tam / 2)) % (int)map->width);
		if(aux_advance_x <= player->tam / 2 && (float)aux_advance_x <= advance_x && aux_advance_x != 0)
			aux_x += (float)aux_advance_x;
		else */ if(check_right_up_p(player, map, advance_x, 0) == 0
			&&check_right_down_p(player, map, advance_x, 0) == 0)
			aux_x += advance_x;	
	}
	return (aux_x);
}
