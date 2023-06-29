/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:02:00 by manujime          #+#    #+#             */
/*   Updated: 2023/06/29 11:52:05 by manujime         ###   ########.fr       */
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

int	ft_is_dir(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

//check if the file exists and has the correct extension
int	ft_file_check(char *str)
{
	int	fd;

	if (ft_is_dir(str) == 1)
	{
		ft_putstr_fd("File is a directory\n", 2);
		return (0);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("File does not exist\n", 2);
		return (0);
	}
	close(fd);
	if (!ft_extension_check(str, ".cub"))
	{
		ft_putstr_fd("Wrong file extension\n", 2);
		return (0);
	}
	return (1);
}
