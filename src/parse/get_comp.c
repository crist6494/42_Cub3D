/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 20:11:26 by manujime          #+#    #+#             */
/*   Updated: 2023/06/29 13:50:46 by manujime         ###   ########.fr       */
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
