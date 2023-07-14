/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:02 by manujime          #+#    #+#             */
/*   Updated: 2023/07/14 19:01:10 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//checks if the map is surrounded by walls '1' no matter the shape

int	ft_walls_re(char **map)
{
	int	i;

	i = ft_walls(map);
	if (i == 2)
	{
		map = NULL;
		ft_putstr_fd("Error\ninvalid map\n", 2);
		return (0);
	}
	if (i == 0)
	{
		ft_free_char_matrix(map);
		map = NULL;
		ft_putstr_fd("Error\ninvalid map\n", 2);
		return (0);
	}
	map = NULL;
	return (1);
}

//checks if a string is completely made of characters from the charset
int	ft_str_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			return (0);
		i++;
	}
	return (1);
}

//gets the map from the file into a matrix of strings
//starts at the index of the map in the file
char	**ft_get_map(t_comp *comp, int i)
{
	int		j;
	int		k;
	char	**map;

	j = 0;
	k = 0;
	while (comp->file[i + j])
		j++;
	map = malloc(sizeof(char *) * (j + 1));
	if (!map)
		return (NULL);
	while (k < j)
	{
		map[k] = ft_strdup(comp->file[i + k]);
		k++;
	}
	map[k] = NULL;
	return (map);
}

static void	ft_map_loader(t_comp *comp, int i)
{
	comp->map = ft_get_map(comp, i);
	if (!ft_walls_re(comp->map))
	{
		ft_putstr_fd("Error\ninvalid map\n", 2);
		ft_exit_parse_error(comp);
	}
	comp->map = ft_get_map(comp, i);
	ft_remove_new_lines(comp->map);
	ft_fill_to_max_len(comp->map, ft_get_len_x(comp->map));
}

//checks that all other components are before the map
int	ft_map_check(t_comp *comp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (comp->file[i])
	{
		if (ft_strnstr(comp->file[i], "NO ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "SO ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "WE ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "EA ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "F ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "C ", ft_strlen(comp->file[i])))
			count++;
		if (ft_strnstr(comp->file[i], "111", ft_strlen(comp->file[i])))
			break ;
		i++;
	}
	if (count != 6)
	{
		ft_putstr_fd("Error\nBad input file\n", 2);
		return (0);
	}
	ft_map_loader(comp, i);
	return (1);
}
