/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:39 by manujime          #+#    #+#             */
/*   Updated: 2023/07/05 15:26:15 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_longest_line(char **map)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

//fills the check string with '1' if there is a wall in the map
int	ft_fill_check(char **check, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1')
				(*check)[j] = '1';
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

int	ft_top_wall(char **map)
{
	int		i;
	int		j;
	int		len;
	char	*check;
	int		result;

	j = 0;
	i = 0;
	result = 1;
	len = ft_longest_line(map);
	check = malloc(sizeof(char) * (len + 1));
	if (!check)
		return (0);
	while (j < len)
	{
		check[j] = '0';
		j++;
	}
	i = ft_fill_check(&check, map);
	if (i == ft_matrix_len(map) || !ft_str_charset(check, "1"))
		result = 0;
	free(check);
	return (result);
}
