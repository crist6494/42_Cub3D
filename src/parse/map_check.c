/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:47:02 by manujime          #+#    #+#             */
/*   Updated: 2023/07/03 18:02:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//checks if a string is completely made of characters from the charset
int	ft_str_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (charset[j])
		{
			if (str[i] == charset[j])
				break ;
			j++;
		}
		if (charset[j] == '\0')
			return (0);
		i++;
	}
	return (1);
}

//checks that all other components are before the map
int	ft_map_check(t_comp *comp)
{
	int	i;
	int	count;

	i = 0;
	while (comp->file[i])
	{
		if (ft_strnstr(comp->file[i], "NO ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "SO ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "WE ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "EA ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "F ", ft_strlen(comp->file[i]))
			|| ft_strnstr(comp->file[i], "C ", ft_strlen(comp->file[i])))
			count++;
		if (ft_str_charset(comp->file[i], "01NSEW "))
			break ;
		i++;
	}
	if (count != 6)
	{
		ft_putstr_fd("Error\nmap not at end of file\n", 2);
		return (0);
	}
	return (1);
}
