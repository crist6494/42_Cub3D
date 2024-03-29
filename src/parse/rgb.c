/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:11:23 by manujime          #+#    #+#             */
/*   Updated: 2023/07/14 18:38:24 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

long int	ft_atol(const char *str)
{
	long int	nbr;
	int			sign;
	int			c;

	nbr = 0;
	sign = 1;
	c = 0;
	while ((str[c] == ' ') || (str[c] == '\t') || (str[c] == '\n')
		|| (str[c] == '\v') || (str[c] == '\f') || (str[c] == '\r'))
		c++;
	if ((str[c] == '-') || (str[c] == '+'))
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		nbr = (nbr * 10) + (str[c] - '0');
		c++;
	}
	return (sign * nbr);
}

//checks if a string has a valid rgb format like "255,255,255"
int	ft_rgb_check(char *str)
{
	int			i;
	long int	aux;
	char		**rgb;

	i = 0;
	rgb = ft_split(str, ',');
	while (rgb[i])
	{
		aux = ft_atol(rgb[i]);
		if (aux < 0 || aux > 255)
		{
			ft_free_char_matrix(rgb);
			ft_putstr_fd("Invalid RGB value\n", 2);
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		ft_free_char_matrix(rgb);
		ft_putstr_fd("Invalid RGB value\n", 2);
		return (0);
	}
	ft_free_char_matrix(rgb);
	return (1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

char	*ft_is_long(char *tmp)
{
	char	*padded_tmp;

	padded_tmp = malloc(3);
	padded_tmp[0] = '0';
	ft_strcpy(padded_tmp + 1, tmp);
	free(tmp);
	tmp = padded_tmp;
	return (tmp);
}

//converts a string in rgb format like "250,250,250"
//to an int hex value like 0xFFFFFF
unsigned int	ft_rgb_to_hex(char *str)
{
	int		i;
	int		aux;
	char	**rgb;
	char	*hex;
	char	*tmp;

	i = 0;
	rgb = ft_split(str, ',');
	hex = ft_strdup("");
	while (rgb[i])
	{
		aux = ft_atoi(rgb[i]);
		tmp = ft_itoa_base(aux, 16);
		if (strlen(tmp) < 2)
			tmp = ft_is_long(tmp);
		hex = ft_strjoin(hex, tmp);
		free(tmp);
		i++;
	}
	ft_free_char_matrix(rgb);
	aux = ft_atoi_base(hex, 16);
	free(hex);
	return (aux);
}
