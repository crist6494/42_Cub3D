/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:39 by manujime          #+#    #+#             */
/*   Updated: 2023/07/14 12:09:44 by cmorales         ###   ########.fr       */
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

void	ft_flood_fill(char **map, int begin_y, int begin_x)
{
	if (map[begin_y][begin_x] == '1' || map[begin_y][begin_x] == 'F'
		|| map[begin_y][begin_x] == '\0')
		return ;
	if (begin_y <= 0 || begin_x < 0 || begin_y >= ft_get_len_y(map) - 1
		|| (unsigned int)begin_x > ft_strlen(map[begin_y]))
		return ;
	map[begin_y][begin_x] = 'F';
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

char	**ft_copy_char_matrix(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (ft_get_len_y(map) + 1));
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_walls(char **map)
{
	t_coord	begin;
	int		valid;
	int		y;
	int		x;
	char	**aux;

	ft_space_map(map);
	aux = ft_copy_char_matrix(map);
	ft_free_char_matrix(map);
	map = ft_first_last_line(aux);
	ft_free_char_matrix(aux);
	valid = ft_count_char(map, ' ');
	begin = ft_get_player_pos(map);
	y = begin.y;
	x = begin.x;
	ft_flood_fill(map, y, x);
	if (valid != ft_count_char(map, ' ') || !ft_str_charset(map[1], "1 \n")
		|| !ft_str_charset(map[ft_get_len_y(map) - 2], "1 \n")
		|| ft_count_char(map, '0'))
	{
		ft_free_char_matrix(map);
		return (2);
	}
	ft_free_char_matrix(map);
	return (1);
}
