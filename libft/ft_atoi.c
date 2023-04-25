/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:35:38 by anmarque          #+#    #+#             */
/*   Updated: 2023/03/21 13:37:13 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <errno.h>

static int	is_out_of_range(unsigned long *value, int sign, char numchar)
{
	unsigned long	ov_div;

	ov_div = LONG_MAX / 10;
	if ((ov_div < *value || (ov_div == *value && numchar > '7')) && sign > 0)
	{
		*value = LONG_MAX;
		return (1);
	}
	if ((ov_div < *value || (ov_div == *value && numchar > '8'))
		&& sign == -1)
	{
		*value = LONG_MAX * -1 - 1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (is_out_of_range(&res, sign, str[i]) == 1)
		{
			errno = 34;
			return ((int)res);
		}
		res = (10 * res) + (str[i] - 48);
		i++;
	}
	res = res * sign;
	return ((int)res);
}

int	ft_atoi_with_check(const char *str, int *result)
{
	int					i;
	unsigned long long	res;
	int					sign;

	sign = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (10 * res) + (str[i] - 48);
		i++;
		if (sign > 0 && res > LONG_MAX)
			return (0);
	}
	*result = res * sign;
	return (res);
}
