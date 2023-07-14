/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:40:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/07/14 12:10:26 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "../memory-leaks/include/memory_leaks.h"
# include "cub3D.h"

/* ---------------------------------------------------------------------------*
	--------------------------------ERRORS---------------------------------
*--------------------------------------------------------------------------- */

# define ERROR_MSG "Error\n"
# define USAGE_MSG "Usage: ./cub3D ./path_to_map\n"

/* ---------------------------------------------------------------------------*
	-------------------------------MEASURES---------------------------------
*--------------------------------------------------------------------------- */

# define WIDTH 2500
# define HEIGHT 1200

# define LINUX_WIDTH 900
# define LINUX_HEIGHT 900

# define COL 10
# define ROW 10

# define N 270
# define S 90
# define W 180
# define E 0

# define FOV 60

/* ---------------------------------------------------------------------------*
	-------------------------------COLORS---------------------------------
*--------------------------------------------------------------------------- */
# define RED 0xFF0000FF
# define GREEN 0x007F007F
# define BLUE 0xADD8E6
# define YELLOW 0xFFFF00FF
# define CYAN 0x00FFFFFF
# define MAGENTA 0xFF00FFFF
# define ORANGE 0xFFA500FF
# define PURPLE 0x800080FF
# define PINK 0xFFC0CBFF
# define LIME 0x00FF00FF
# define BROWN 0x8B4513FF
# define NAVY 0x000080FF
# define TEAL 0x008080FF
# define MAROON 0x800000FF
# define OLIVE 0x808000FF
# define SILVER 0xC0C0C0FF
# define GREY 0x808080FF
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF

#endif