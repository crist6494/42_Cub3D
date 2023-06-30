/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/06/30 12:35:28 by manujime         ###   ########.fr       */
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

typedef struct s_paint_p{
	int		x;
	int		y;
}t_paint_p;

typedef struct s_4square{
	t_paint_p p0;
	t_paint_p p1;
	t_paint_p p2;
	t_paint_p p3;
}t_4square;

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
	t_coord			*p_square;
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
	int				screen_x;
	int				screen_y;
	int				fov;
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

typedef struct s_ray
{
	int				down;
	int				left;
	float			rads_angle;
	t_coord			*coordHitHorizontal;
	t_coord			*coordHitVertical;
}t_ray;

typedef struct s_comp
{
	char	**file;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_rgb;
	char	*c_rgb;
	char	**map;
}t_comp;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	*player;	
	t_map		*map;
	t_ray		*ray;
	t_comp		*comp;
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

/*----Parse------*/
void	ft_parse(t_game *game, char *av);

/*-----Argv-Check-----*/
int		ft_extension_check(char *str, char *ex);
int		ft_file_check(char *str);

/*-----Get-Comp*/
void	ft_get_file(t_comp *comp, char *file);
char	*ft_get_comp_line(t_comp *comp, char *name);

/*-----Parse-Utils-----*/
void	ft_free_char_matrix(char **arr);
void	ft_print_char_matrix(char **matrix);
void	ft_init_comp(t_game *game);

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
void paint_line(t_point *p, mlx_image_t *img, uint32_t color);



/*------Player---------*/
void	init_player(t_player *player, t_game *game, t_square *square);
void	update_direction(t_player *player);
void	pos_line(t_player *player);
void	pos_player_map(t_map *map, t_player *player, t_square *square);


/*------Player_Paint---------*/
void	paint_player(t_game *game, t_player *player);
void	repaint(t_game *game, t_player *player);

/*------Player_Utils---------*/
float	grades_to_rad(float angle);
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
void	check_collision(t_map *map, t_player *player, float advance_x, float advance_y);
void	get_square_corner(t_player *player, t_square *square);

/*---------Collisions_sides-------------*/
int		check_left_down_p(t_player * player, t_map *map, float advance_x, float advance_y);
int		check_right_down_p(t_player * player, t_map *map, float advance_x, float advance_y);
int		check_left_up_p(t_player * player, t_map *map, float advance_x, float advance_y);
int		check_right_up_p(t_player * player, t_map *map, float advance_x, float advance_y);


/*---------Collisions_utils-------------*/
float	check_up_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float	check_down_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float	check_left_collision(t_player *player, t_map *map, float advance_x, float advance_y);
float	check_right_collision(t_player *player, t_map *map, float advance_x, float advance_y);

void	init_ray(t_ray *data, float angle);
float	raycast(t_game *game, t_player *player, t_ray *ray, float angle);
void	raycast_horizonal(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitHorizontal);
void	raycast_vertical(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitVertical);

void	cast(t_game *game, t_player *player, t_ray *ray);
void	paint_ceil_floor(t_player *player);
float	normalize_angle(float angle);
float	raycast(t_game *game, t_player *player, t_ray *ray, float angle);
# endif