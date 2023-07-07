/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:13:41 by manujime          #+#    #+#             */
/*   Updated: 2023/07/07 18:39:41 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_numlen(int n, int base)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		i++;
		j--;
	}
	return (str);
}

static char	ft_base(int n)
{
	if (n < 10)
		return (n + '0');
	else
		return (n - 10 + 'A');
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0 && base == 10)
		neg = 1;
	if (n < 0)
		n *= -1;
	str = (char *)malloc(sizeof(char) * (ft_numlen(n, base) + neg + 1));
	if (!str)
		return (NULL);
	while (n != 0)
	{
		str[i++] = ft_base(n % base);
		n /= base;
	}
	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
