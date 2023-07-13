/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:18:24 by manujime          #+#    #+#             */
/*   Updated: 2023/07/13 19:34:13 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	n;
	int	neg;

	i = 0;
	n = 0;
	neg = 0;
	if (str[i] == '-')
		neg = 1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			n = n * base + (str[i] - '0');
		else if (ft_isalpha(str[i]))
			n = n * base + (ft_toupper(str[i]) - 'A' + 10);
		i++;
	}
	if (neg)
		n *= -1;
	return (n);
}

//adds an extra line at the beggining and end of the map
//and fills the lines with ' '
char	**ft_first_last_line(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (ft_get_len_y(map) + 3));
	new_map[0] = ft_strdup(" ");
	while (ft_strlen(new_map[0]) < (size_t)ft_get_len_x(map))
		new_map[0] = ft_strjoin(new_map[0], " ");
	while (map[i])
	{
		new_map[i + 1] = ft_strdup(map[i]);
		i++;
	}
	new_map[i + 1] = ft_strdup(new_map[0]);
	new_map[i + 2] = NULL;
	return (new_map);
}
