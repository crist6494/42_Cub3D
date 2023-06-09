/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/09 20:16:00 by cmorales         ###   ########.fr       */
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
typedef struct s_coord{
	float x;
	float y;
}t_coord;

typedef struct s_point{
	float x;
	float y;
	float x1;
	float y1;
	int err;
	int e2;
	int dy;
	int dx;
}t_point;

typedef struct s_player
{
	t_coord			*p_center;
	t_coord			*direction;
	t_point			*p_line;
	mlx_image_t		*img;
	mlx_t			*mlx;
	int				tam;
	unsigned int	color;
	float			dir_x;
	float			dir_y;
	int				len_dir;
	float			move;
	float				angle;
	int				vel_move;
	float			vel_turn; 
}t_player;

typedef struct s_map{
	t_coord			*m_coord;
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
void init_map(t_map *map, char *path_map);
void	read_map(t_map *map);
void create_map(t_game *game, t_map *map, float c_x, float c_y);
void	paint_map(t_game *game, t_map *map, t_coord *coord);

/*-----Map-Utils-----*/
void	error(void);
void	map_print(t_game *game);
void	clear_map(t_game *game);

/*-----Paint-----*/
void insert_coord(t_coord *c, float x, float y);
void init_points(t_point *p, t_coord *c, t_coord *c1);
void paint_line(t_point *p, mlx_image_t *img);
void square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);
//void paint_player(t_coord *coord, mlx_image_t *img);

/*-----Hooks-----*/
void hook(mlx_key_data_t keydata, void *param);
//void move_hook(mlx_key_data_t keydata, void *param);
void hook_screen(int32_t width, int32_t height, void* param);

void ft_void();

void paint_player(t_game *game, t_player *player);

void player_advance(t_game *game, t_player *player, int direction);

void move_hook(void *param);

void init_player(t_player *player, t_game *game);


void update_direction(t_player *player);

void rotate(t_game *game, t_player *player, int clockwise);

void get_map_lens(t_map *map, char *path);
void save_map(t_map *map, char *path);

int get_len_y(char *path);
int get_len_x(char *path);

void get_map_lens(t_map *map, char *path);
void save_map(t_map *map, char *path);

int get_len_y(char *path);
int get_len_x(char *path);
void free_map(t_map *map);
# endif