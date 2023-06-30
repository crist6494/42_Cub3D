/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:43 by manujime          #+#    #+#             */
/*   Updated: 2023/06/30 14:42:46 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//checks if there is more than one instance of the name string in the file
int	ft_check_n_str(char **file, char *name)
{
	int		instances;
	int		i;

	instances = 0;
	i = 0;
	while (file[i])
	{
		if (ft_strnstr(file[i], name, ft_strlen(file[i])))
		{
			instances++;
			if (instances >= 1)
				return (instances);
		}
		i++;
	}
	printf("%s instances: %d\n", name, instances);
	return (instances);
}

//gets all the components from the file
void	ft_get_comps(t_comp *comp)
{
	comp->no_path = ft_get_comp_line(comp, "NO ");
	comp->so_path = ft_get_comp_line(comp, "SO ");
	comp->we_path = ft_get_comp_line(comp, "WE ");
	comp->ea_path = ft_get_comp_line(comp, "EA ");
	comp->f_rgb = ft_get_comp_line(comp, "F ");
	comp->c_rgb = ft_get_comp_line(comp, "C ");
	if (!ft_extension_check(comp->no_path, ".xpm")
		|| !ft_extension_check(comp->so_path, ".xpm")
		|| !ft_extension_check(comp->we_path, ".xpm")
		|| !ft_extension_check(comp->ea_path, ".xpm"))
	{
		ft_putstr_fd("Error\nBad texture file\n", 2);
		exit(0);
	}
}

//stores the file in the comp struct, and processes the contents
void	ft_parse(t_game *game, char *av)
{
	char	**file;

	ft_init_comp(game);
	ft_get_file(game->comp, av);
	file = game->comp->file;
	if (ft_check_n_str(file, "NO ") != 1 || ft_check_n_str(file, "SO ") != 1
		|| ft_check_n_str(file, "WE ") != 1 || ft_check_n_str(file, "EA ") != 1
		|| ft_check_n_str(file, "F ") != 1 || ft_check_n_str(file, "C ") != 1)
	{
		ft_putstr_fd("Error\nBad components in file\n", 2);
		exit(0);
	}
	ft_get_comps(game->comp);
	exit(0);
}
