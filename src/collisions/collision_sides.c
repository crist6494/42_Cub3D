/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sides.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:22:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/19 20:34:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
	/*int		aux_advance_y;
	float	aux_y;

	aux_y = player->pos_y;
	if (check_right_up_player(player, map, advance_x, advance_y) == 0
		&& check_left_up_player(player, map, advance_x, advance_y) == 0)
	{
		aux_y += advance_y;
	}
	else
	{
		aux_advance_y = (((int)player->pos_y - (player->tam / 2)) % map->height);
		if (aux_advance_y <= (int)(player->tam / 2) && (float)aux_advance_y <= (-1.0 * advance_y)
				&& aux_advance_y != 0)
			aux_y -= (float)aux_advance_y;
		else if (check_right_up_player(player, map, 0, advance_y) == 0
			&& check_left_up_player(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}*/


float check_up_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_y;
	//int aux_advance_y;

	aux_y = player->square->p_center->y;
	if(check_right_up_p(player, map, advance_x, advance_y) == 0
		&&check_left_up_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	/* else
	{
		aux_advance_y = (((int)player->square->p_center->y - (player->tam / 2)) % map->height);
		if(aux_advance_y <= (player->tam / 2) && (float)aux_advance_y <= (-1.0 * advance_y) && aux_advance_y != 0)
			aux_y -= (float)aux_advance_y;
		else if(check_right_up_p(player, map, advance_x, advance_y) == 0
			&&check_left_up_p(player, map, advance_x, advance_y) == 0)
			aux_y += advance_y;
	} */
	return (aux_y);
}

/*float	check_down_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_y;
	float	aux_y;
	aux_y = player->pos_y;
	if (check_right_down_player(player, map, advance_x, advance_y) == 0
		&& check_left_down_player(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	else
	{
		aux_advance_y = map->height - (((int)player->pos_y + (player->tam / 2)) % map->height);
		if (aux_advance_y <= (int)(player->tam / 2) && (float)aux_advance_y <= advance_y && aux_advance_y != 0)
			aux_y += (float)aux_advance_y;
		else if (check_right_down_player(player, map, 0, advance_y) == 0
			&& check_left_down_player(player, map, 0, advance_y) == 0)
			aux_y += advance_y;
	}
	return (aux_y);
}*/

float check_down_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_y;
	//int aux_advance_y;

	aux_y = player->square->p_center->y;
	if(check_right_down_p(player, map, advance_x, advance_y) == 0
		&&check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_y += advance_y;
	/* else
	{
		aux_advance_y = map->height - (((int)player->square->p_center->y + (player->tam / 2)) % map->height);
		if(aux_advance_y <= (player->tam / 2) && (float)aux_advance_y <= advance_y && aux_advance_y != 0)
			aux_y += (float)aux_advance_y;
		else if(check_right_up_p(player, map, advance_x, advance_y) == 0
			&&check_left_up_p(player, map, advance_x, advance_y) == 0)
			aux_y += advance_y;
	} */
	return (aux_y);
}


/*float	check_left_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_x;
	float	aux_x;

	aux_x = player->pos_x;
	if (check_left_down_player(player, map, advance_x, advance_y) == 0
		&& check_left_up_player(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		aux_advance_x = (((int)player->pos_x - (player->tam / 2)) % map->width);
		if (aux_advance_x <= (int)(player->tam / 2) && (float)aux_advance_x <= (-1.0 * advance_x) && aux_advance_x != 0)
			aux_x -= (float)aux_advance_x;
		else if (check_left_down_player(player, map, advance_x, 0) == 0
			&& check_left_up_player(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}*/

float check_left_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	//int aux_advance_x;

	aux_x = player->square->p_center->x;
	if(check_left_up_p(player, map, advance_x, advance_y) == 0
		&&check_left_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	/* {
		aux_advance_x = (((int)player->square->p_center->x - player->tam / 2) % map->width);
		if(aux_advance_x <= player->tam / 2 && (float)aux_advance_x <= (1.0 * advance_x) && aux_advance_x != 0)
			aux_x -= (float)aux_advance_x;
		else if(check_left_up_p(player, map, advance_x, advance_y) == 0
			&&check_left_down_p(player, map, advance_x, advance_y) == 0)
			aux_x += advance_x;
	} */
	return (aux_x);
}

/*float	check_right_collisions(t_map *map, t_player *player,
			float advance_x, float advance_y)
{
	int		aux_advance_x;
	float	aux_x;

	aux_x = player->pos_x;
	if (check_right_down_player(player, map, advance_x, advance_y) == 0
		&& check_right_up_player(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
	else
	{
		aux_advance_x = map->width - (((int)player->pos_x + (player->tam / 2)) % map->width);
		if (aux_advance_x <= (int)(player->tam / 2) && (float)aux_advance_x <= advance_x && aux_advance_x != 0)
			aux_x += (float)aux_advance_x;
		else if (check_right_down_player(player, map, advance_x, 0) == 0
			&& check_right_up_player(player, map, advance_x, 0) == 0)
			aux_x += advance_x;
	}
	return (aux_x);
}*/

float check_right_collision(t_player *player, t_map *map, float advance_x, float advance_y)
{
	float aux_x;
	//int aux_advance_x;

	aux_x = player->square->p_center->x;
	if(check_right_up_p(player, map, advance_x, advance_y) == 0
		&&check_right_down_p(player, map, advance_x, advance_y) == 0)
		aux_x += advance_x;
/* 	else
	{
		aux_advance_x = map->width - (((int)player->square->p_center->x + (player->tam / 2)) % map->width);
		if(aux_advance_x <= player->tam / 2 && (float)aux_advance_x <= advance_x && aux_advance_x != 0)
			aux_x += (float)aux_advance_x;
		else if(check_right_up_p(player, map, advance_x, advance_y) == 0
			&&check_right_down_p(player, map, advance_x, advance_y) == 0)
			aux_x += advance_x;	
	} */
	return (aux_x);
}
