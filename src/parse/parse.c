/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:17:43 by manujime          #+#    #+#             */
/*   Updated: 2023/07/07 18:37:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//checks if there is more than one instance of the name string in the file
static int	ft_check_n_str(char **file, char *name)
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
static void	ft_get_comps(t_comp *comp)
{
	comp->no_path = ft_get_comp_line(comp, "NO ");
	comp->so_path = ft_get_comp_line(comp, "SO ");
	comp->we_path = ft_get_comp_line(comp, "WE ");
	comp->ea_path = ft_get_comp_line(comp, "EA ");
	comp->f_rgb = ft_get_comp_line(comp, "F ");
	comp->c_rgb = ft_get_comp_line(comp, "C ");
	if (!ft_extension_check(comp->no_path, ".png")
		|| !ft_extension_check(comp->so_path, ".png")
		|| !ft_extension_check(comp->we_path, ".png")
		|| !ft_extension_check(comp->ea_path, ".png"))
	{
		ft_putstr_fd("Error\nNot png textures\n", 2);
		ft_exit_parse_error(comp);
	}
	if (!ft_rgb_check(comp->f_rgb) || !ft_rgb_check(comp->c_rgb))
		ft_exit_parse_error(comp);
	comp->f_hex = ft_rgb_to_hex(comp->f_rgb);
	comp->c_hex = ft_rgb_to_hex(comp->c_rgb);
	if (!ft_map_check(comp))
		ft_exit_parse_error(comp);
	if (comp->map == NULL)
	{
		ft_putstr_fd("Error\nbad map\n", 1);
		ft_exit_parse_error(comp);
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
		ft_exit_parse_error(game->comp);
	}
	ft_get_comps(game->comp);
	ft_get_textures(game);
}
