/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/19 20:39:24 by cmorales         ###   ########.fr       */
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
//#include "../memory-leaks/include/memory_leaks.h"

/* ---------------------------------------------------------------------------*
	-------------------------------STRUCTURES---------------------------------
*--------------------------------------------------------------------------- */
typedef struct s_coord{
	float	x;
	float	y;
}t_coord;

typedef struct s_point{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		sx;
	int		sy;
	float	dy;
	float	dx;
}t_point;

typedef struct s_square{
	t_coord			*p_center;
	t_coord			*mid_square;
	t_coord			*p_left_down;
	t_coord			*p_right_down;	
	t_coord			*p_left_up;	
	t_coord			*p_right_up;	
}t_square;

typedef struct s_player
{
	t_square		*square;
	t_coord			*pos_map;
	t_coord			*direction;
	t_point			*p_line;
	mlx_image_t		*img;
	mlx_t			*mlx;
	int				tam;
	unsigned int	color;
	float			dir_x;
	float			dir_y;
	int				len_dir;
	int				angle;
	float			vel_move;
}t_player;

typedef struct s_map{
	mlx_image_t		*img;
	t_coord			*m_coord;
	t_coord			*mid_map;
	unsigned int	len_x;
	unsigned int	len_y;
	unsigned int	width;
	unsigned int	height;
	float			lim;
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
}t_game;

/* ---------------------------------------------------------------------------*
	-------------------------------FUCTIONS---------------------------------
*--------------------------------------------------------------------------- */


/*-----Map-----*/
void	init_map(t_map *map, char *path_map);
void	create_map(t_game *game, t_map *map, float c_x, float c_y);
void	paint_map(t_game *game, t_map *map, char *map_path);


/*-----Parse-Map-----*/
int		get_len_y(char *path);
int		get_len_x(char *path);
char	**alloc_map(t_map *map);
void	fill_map(t_map *map, char **tour);
void	fill_values_map(t_map *map, char **tour, char *path);


/*-----Map-Utils-----*/
void	free_map(t_map *map);
void	map_print(t_map *map);
void	clear_map(t_map *map);


/*-------Map-Data--------*/
int		get_player_angle(t_map *map);
t_coord get_player_pos(t_map *map);



/*-----Paint-----*/
void	insert_coord(t_coord *c, float x, float y);
void	init_points(t_point *p, t_coord *c, t_coord *c1);
void	square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);
void	paint_line(t_point *p, mlx_image_t *img);



/*------Player---------*/
void init_player(t_player *player, t_game *game, t_square *square);
void	update_direction(t_player *player);
void	pos_line(t_player *player);
void pos_player_map(t_map *map, t_player *player, t_square *square);


/*------Player_Paint---------*/
void	paint_player(t_game *game, t_player *player);
void	repaint(t_game *game, t_player *player);

/*------Player_Utils---------*/
float	grades_to_rad(double angle);
void	free_player(t_player *player);


/*--------Movement--------------*/
void	player_advance(t_game *game, t_player *player, int direction);
void	rotate(t_game *game, t_player *player, int clockwise);
void	player_lateral(t_game *game, t_player *player, int direction);



/*-----Hooks-----*/
void	hook(mlx_key_data_t keydata, void *param);
void	move_hook(void *param);
void	hook_screen(int32_t width, int32_t height, void* param);



/*---------Utils-------------*/
void	ft_void();
void	error(void);
int		print_error(char *msg);
void		check_collision(t_map *map, t_player *player, float advance_x, float advance_y);
void	get_square_corner(t_player *player, t_square *square);


int check_left_down_p(t_player * player, t_map *map, float advance_x, float advance_y);
int check_right_down_p(t_player * player, t_map *map, float advance_x, float advance_y);
int check_left_up_p(t_player * player, t_map *map, float advance_x, float advance_y);
int check_right_up_p(t_player * player, t_map *map, float advance_x, float advance_y);

float check_up_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float check_down_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float check_left_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float check_right_collision(t_player *player, t_map *map, float advance_x, float advance_y);

# endif