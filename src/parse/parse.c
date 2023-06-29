/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:43 by manujime          #+#    #+#             */
/*   Updated: 2023/06/29 19:33:42 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//checks if there is more than one instance of the name string in the file
int	ft_check_n_str(char **file, char *name)
{
	int		instances;
	int		i;
	char	*aux;

	instances = 0;
	i = 0;
	aux = NULL;
	while (file[i])
	{
		aux = ft_strnstr(file[i], name, ft_strlen(file[i]));
		if (aux != NULL)
		{
			instances++;
			if (instances >= 1)
				file[i] += (ft_strlen(file[i])
						- ft_strlen(aux) + ft_strlen(name));
			aux = NULL;
			continue ;
		}
		i++;
	}
	printf("%s instances: %d\n", name, instances);
	return (instances);
}

//searches the file for the paths to the textures and saves them even if
//the name and the path can be separated by any number of spaces
//or in different lines
void	ft_get_paths(t_comp *comp, char *name)
{
	int		i;
	char	*aux;

	i = 0;
	while (comp->file[i])
	{
		if (ft_strnstr(comp->file[i], name, ft_strlen(comp->file[i])))
		{
			aux = ft_strnstr(comp->file[i], name, ft_strlen(comp->file[i]));
			break ;
		}
		i++;
	}
}

//stores the file in the comp struct, and processes the contents
void	ft_parse(t_game *game, char *av)
{
	char	**file;

	ft_init_comp(game);
	ft_get_file(game->comp, av);
	file = game->comp->file;
	ft_print_char_matrix(game->comp->file);
	if (ft_check_n_str(file, "NO ") != 1 || ft_check_n_str(file, "SO ") != 1
		|| ft_check_n_str(file, "WE ") != 1 || ft_check_n_str(file, "EA ") != 1
		|| ft_check_n_str(file, "F ") != 1 || ft_check_n_str(file, "C ") != 1)
	{
		ft_putstr_fd("Error\nBad components in file\n", 2);
		exit(0);
	}
	ft_print_char_matrix(game->comp->file);
	ft_get_paths(game->comp, "NO ");
	exit(0);
}
