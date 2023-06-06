/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/06 19:05:29 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include "libft.h"
#include "MLX42/MLX42.h"
#include "macros.h"

/* ---------------------------------------------------------------------------*
	-------------------------------STRUCTURES---------------------------------
*--------------------------------------------------------------------------- */

typedef struct s_point{
	int x0; 
	int y0;
	int x1;
	int y1;
	int ix;
	int iy;
	int err;
	int dy;
	int dx;
	int x;
	int y;
}t_point;

typedef struct s_coord{
	float x;
	float y;
}t_coord;

typedef struct s_player
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	int				tam;
	unsigned int	color;
	float			p_x;	
	float			p_y;
	float			move;
	float			turn;
	float			angle;
	int				vel_move;
	float			vel_turn;
}t_player;

typedef struct s_map{
	unsigned int	len_x;
	unsigned int	len_y;
	float			lim;
	float			map_width;
	float			map_height;
	float			half_x;
	float			half_y;
	float			pos_x;
	float			pos_y;
	char			**tour;
}t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	*player;	
	t_map		*map;
	t_coord		*coord;
}t_game;

/* ---------------------------------------------------------------------------*
	-------------------------------FUCTIONS---------------------------------
*--------------------------------------------------------------------------- */


/*-----Map-----*/

void	read_map(t_map *map);
void	create_map(t_game *game,t_coord *coord, float c_y, float c_x);
void	paint_map(t_game *game, t_map *map, t_coord *coord);

/*-----Map-Utils-----*/
void	error(void);
void	map_print(t_game *game);
void	clear_map(t_game *game);

/*-----Paint-----*/
void insert_coord(t_coord *c, float y, float x);
void line(t_point *p, mlx_image_t *img);
void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);
//void paint_player(t_coord *coord, mlx_image_t *img);

/*-----Hooks-----*/
void hook(mlx_key_data_t keydata, void *param);
//void move_hook(mlx_key_data_t keydata, void *param);
void hook_screen(int32_t width, int32_t height, void* param);

void ft_void();

void paint_player(t_game *game, t_player *player, float y, float x);

void player_advance(t_game *game, t_player *player, int direction);

void move_hook(void *param);

# endif