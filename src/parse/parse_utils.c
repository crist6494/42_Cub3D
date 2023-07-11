/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:39:52 by manujime          #+#    #+#             */
/*   Updated: 2023/07/11 11:49:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//frees a char **
void	ft_free_char_matrix(char **arr)
{
	char	**current;

	if (arr == NULL)
		return ;
	current = arr;
	while (*current)
	{
		free(*current);
		current++;
	}
	free(arr);
}

//prints a char **
void	ft_print_char_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

//initializes the comp struct in the game struct
void	ft_init_comp(t_game *game)
{
	game->comp = malloc(sizeof(t_comp));
	game->comp->file = NULL;
	game->comp->no_path = NULL;
	game->comp->so_path = NULL;
	game->comp->we_path = NULL;
	game->comp->ea_path = NULL;
	game->comp->f_rgb = NULL;
	game->comp->c_rgb = NULL;
	game->comp->no = NULL;
	game->comp->so = NULL;
	game->comp->we = NULL;
	game->comp->ea = NULL;
	game->comp->map = NULL;
}


//checks that all chars in the map matrix are in the tiles string
int	ft_map_tiles(char **map, char *tiles)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_str_charset(map[i], tiles))
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_to_max_len(char **map, int max_len)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < (size_t)max_len)
			map[i] = ft_strjoin(map[i], " ");
		if (ft_strlen(map[i]) >= (size_t)max_len)
			i++;
	}
}
