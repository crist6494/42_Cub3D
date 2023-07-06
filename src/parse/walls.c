/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:39 by manujime          #+#    #+#             */
/*   Updated: 2023/07/06 05:07:11 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_count_char(char **map, char c)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == c)
				count++;
			k++;
		}
		i++;
	}
	return (count);
}

t_paint_p	ft_get_player_yx(char **map)
{
	t_paint_p	begin;
	int			y;
	int			x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				begin.x = x;
				begin.y = y;
			}
			x++;
		}
		y++;
	}
	return (begin);
}

void	ft_flood_fill(char **map, int begin_y, int begin_x)
{
	if (map[begin_y][begin_x] == '1' || map[begin_y][begin_x] == 'F'
		|| map[begin_y][begin_x] == '\0')
		return ;
	if (begin_y <= 0 || begin_x < 0 || begin_y >= ft_matrix_len(map) -1
		|| (unsigned int)begin_x > ft_strlen(map[begin_y]))
		return ;
	map[begin_y][begin_x] = 'F';
	printf("begin.x: %d\n", begin_x);
	printf("begin.y: %d\n", begin_y);
	ft_flood_fill(map, begin_y - 1, begin_x);
	ft_flood_fill(map, begin_y + 1, begin_x);
	ft_flood_fill(map, begin_y, begin_x - 1);
	ft_flood_fill(map, begin_y, begin_x + 1);
}

//adds an extra space to the beginning of each line
//replace the \n at the end of each line with a space
void	ft_space_map(char **map)
{
	char	*aux;
	char	*space;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		space = ft_strdup(" ");
		aux = ft_strdup(map[i]);
		free(map[i]);
		map[i] = ft_strjoin(space, aux);
		free(aux);
		i++;
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '\n')
				map[i][j] = ' ';
		}
	}
}

int	ft_walls(char **map)
{
	t_paint_p	begin;
	int			valid;
	int			y;
	int			x;

	ft_space_map(map);
	valid = ft_count_char(map, ' ');
	begin = ft_get_player_yx(map);
	y = begin.y;
	x = begin.x;
	ft_print_char_matrix(map);
	ft_flood_fill(map, y, x);
	ft_print_char_matrix(map);
	if (valid != ft_count_char(map, ' ') || !ft_str_charset(map[0], "1 \n")
		|| !ft_str_charset(map[ft_matrix_len(map) - 1], "1 \n"))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	return (1);
}