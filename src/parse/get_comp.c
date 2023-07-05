/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:11:26 by manujime          #+#    #+#             */
/*   Updated: 2023/07/05 12:35:16 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//gets the number of lines in the file
int	ft_file_len(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

//saves the content of the file into the comp struct as a char **
void	ft_get_file(t_comp *comp, char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	comp->file = malloc(sizeof(char *) * (ft_file_len(file) + 1));
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		comp->file[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	comp->file[i] = NULL;
	close(fd);
}

//returns the value of the component passed as a string
char	*ft_get_comp_line(t_comp *comp, char *name)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	while (comp->file[i])
	{
		if (ft_strnstr(comp->file[i], name, ft_strlen(comp->file[i])))
		{
			line = ft_strdup(comp->file[i]);
			tmp = ft_split(line, ' ');
			free(line);
			line = ft_strdup(tmp[1]);
			ft_free_char_matrix(tmp);
			i = ft_strlen(line);
			if (i > 0 && line[i - 1] == '\n')
				line[i - 1] = '\0';
			return (line);
		}
		i++;
	}
	return (NULL);
}

//gets the textures from the paths in the comp struct
void	ft_get_textures(t_game *game)
{
	bool	loaded;

	loaded = true;
	game->comp->no = mlx_load_png(game->comp->no_path);
	if (game->comp->no == NULL)
		loaded = false;
	game->comp->so = mlx_load_png(game->comp->so_path);
	if (game->comp->so == NULL)
		loaded = false;
	game->comp->we = mlx_load_png(game->comp->we_path);
	if (game->comp->we == NULL)
		loaded = false;
	game->comp->ea = mlx_load_png(game->comp->ea_path);
	if (game->comp->ea == NULL)
		loaded = false;
	if (!loaded)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("bad texture file\n", 1);
		exit(0);
	}
}
