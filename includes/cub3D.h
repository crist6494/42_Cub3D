/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:20:57 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/07 20:51:08 by cmorales         ###   ########.fr       */
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
	char			**file;
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*f_rgb;
	char			*c_rgb;
	int				f_hex;
	int				c_hex;
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	char			**map;
}t_comp;

typedef struct s_minimap
{
	mlx_image_t	*img;
	int			len_x;
	int			len_y;
	int			cas_x;
	int			cas_y;
}t_minimap;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player	*player;	
	t_map		*map;
	t_minimap	*minimap;
	t_ray		*ray;
	t_comp		*comp;
}t_game;


/* ---------------------------------------------------------------------------*
	-------------------------------FUCTIONS---------------------------------
*--------------------------------------------------------------------------- */

/* ------------------------------*
	-----------PARSE-----------
*--------------------------------*/
void	ft_parse(t_game *game, char *av);

/*-----Argv-Check-----*/
int		ft_extension_check(char *str, char *ex);
int		ft_file_check(char *str);

/*-----Get-Comp------*/
void	ft_get_file(t_comp *comp, char *file);
char	*ft_get_comp_line(t_comp *comp, char *name);
void	ft_get_textures(t_game *game);

/*----Map-Check-----*/
int		ft_str_charset(char *str, char *charset);
int		ft_map_check(t_comp *comp);

/*-----rgb-------*/
int				ft_rgb_check(char *str);
unsigned int	ft_rgb_to_hex(char *str);

/*-----Parse-Utils-----*/
void	ft_free_char_matrix(char **arr);
void	ft_print_char_matrix(char **matrix);
void	ft_init_comp(t_game *game);
int		ft_map_tiles(char **map, char *tiles);

/*----walls----*/
int		ft_count_char(char **map, char c);
void	ft_flood_fill(char **map, int begin_y, int begin_x);
int		ft_walls(char **map);

/*-----itoa_base-----*/
char	*ft_itoa_base(int n, int base);

/*-----atoi_base-----*/
int		ft_atoi_base(char *str, int base);

/*----clean-up----*/
void	ft_exit_parse_error(t_comp *comp);



/* ------------------------------*
	-----------MAP-----------
*--------------------------------*/
void	init_map(t_game *game, t_map *map, char *path_map);
void	create_map(t_game *game, t_map *map, float c_x, float c_y);

/*-------Map-Data--------*/
int		ft_get_player_angle(char **map);
t_coord	ft_get_player_pos(char **map);
int		ft_get_len_x(char **map);
int		ft_get_len_y(char **map);

/*-----Map-Utils-----*/
void	free_map(t_map *map);
void	map_print(t_map *map);
void	clear_map(t_map *map);

/*-----Minimap-----*/
void 	init_minimap(t_game *game, t_minimap *minimap, int width, int height);
void	paint_minimap_background(t_game *game);
void	paint_minimap(t_game *game, t_minimap *mp);


/* ------------------------------*
	-----------PLAYER-----------
*--------------------------------*/
void	init_player(t_player *player, t_game *game, t_square *square);
void	update_direction(t_player *player);
void	pos_line(t_player *player);
void	pos_player_map(t_map *map, t_player *player, t_square *square);

/*------Player_Utils---------*/
float	grades_to_rad(float angle);
void	free_player(t_player *player);
void	get_square_corner(t_player *player, t_square *square);

/*--------Movement--------------*/
void	player_advance(t_game *game, t_player *player, int direction);
void	rotate(t_game *game, t_player *player, int clockwise);
void	player_lateral(t_game *game, t_player *player, int direction);



/* ------------------------------*
	-----------PAINT-----------
*--------------------------------*/
void	square_paint(t_coord *coord, float lim, uint32_t color, mlx_image_t *img);
void	paint_line(t_point *p, mlx_image_t *img, uint32_t color);
void	paint_ceil_floor(t_player *player);

/*------Coord_paint_p---------*/
void	insert_coord(t_coord *c, float x, float y);
void	init_points(t_point *p, t_coord *c, t_coord *c1);
void	insert_paint_p(t_paint_p *c, int x, int y);

/*------Repaint---------*/
void	repaint(t_game *game, t_player *player);



/* ------------------------------*
	-----------HOOKS-----------
*--------------------------------*/
void	escape_hook(mlx_key_data_t keydata, void *param);
void	hook_screen(int32_t width, int32_t height, void* param);
void	cursor_hook(double xpos, double ypos, void* param);
void	move_hook(void *param);



/* ------------------------------*
	---------COLLISIONS---------
*--------------------------------*/
void 	check_collision(t_map *map, t_player *player, float advance_x, float advance_y);

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



/* ------------------------------*
	--------RAYCASTING--------
*--------------------------------*/
void	cast(t_game *game, t_player *player, t_ray *ray);

/*---------Raycast-------------*/
void	init_ray(t_ray *data, float angle);
float	raycast(t_game *game, t_player *player, t_ray *ray, float angle);

/*---------Raycast_Horizontal-------------*/
void	raycast_horizonal(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitHorizontal);

/*---------Raycast_Vertical-------------*/
void	raycast_vertical(t_map *map, t_player *player, t_ray *ray, t_coord *wallHitVertical);



/* ------------------------------*
	--------UTILS--------
*--------------------------------*/
void	ft_void();
void	error(void);
int		print_error(char *msg);
float	normalize_angle(float angle);

# endif