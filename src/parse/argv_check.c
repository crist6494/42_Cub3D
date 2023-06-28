/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:02:00 by manujime          #+#    #+#             */
/*   Updated: 2023/06/28 20:18:16 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//check if the file extension is corect
int	ft_extension_check(char *str, char *ex)
{
	int		len;
	int		ex_len;
	char	*aux;

	len = ft_strlen(str);
	ex_len = ft_strlen(ex);
	if (len < ex_len)
		return (0);
	aux = str + (len - ex_len);
	if (ft_strcmp(aux, ex) == 0)
		return (1);
	else
		return (0);
}

//check if the file exists
int	ft_file_check(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile does not exist\n", 2);
		return (0);
	}
	close(fd);
	return (1);
}

//checks if the component name and content are in the same line
//if they are, it saves the content in the components struct
//and returns 1, else it returns 0
int	ft_check_line(char *line, char *comp, t_comp *components)
{
	while (line && *line == ' ')
		line++;
	if (ft_strnstr(comp, line, ft_strlen(comp)) != 0)
	{
		return
	}
}

//checks if the file has all the necessary components
//and saves them in the components struct
int	ft_is_valid_file(char *str, t_comp *components)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strnstr("NO SO WE EA FL C", line, 2) != 0)

		free(line);
		line = get_next_line(fd);
	}
}
