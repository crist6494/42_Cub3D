/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:43 by manujime          #+#    #+#             */
/*   Updated: 2023/06/29 16:13:24 by manujime         ###   ########.fr       */
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
	if (instances > 1 || instances == 0)
		return (1);
	return (0);
}

//searches the file for the paths to the textures and saves them
//it checks if the paths are valid and that there are no duplicates
void	ft_get_paths(t_game *game)
{
	int	i;

	i = 0;
	while (game->comp->file[i])
	{

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
	//ft_print_char_matrix(game->comp->file);
	if (ft_check_n_str(file, "NO") || ft_check_n_str(file, "SO")
		|| ft_check_n_str(file, "WE") || ft_check_n_str(file, "EA"))
	{
		ft_putstr_fd("Error\nBad cardinal texture paths\n", 2);
		exit(0);
	}
	ft_get_paths(game);
	exit(0);
}
