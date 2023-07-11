/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:18:24 by manujime          #+#    #+#             */
/*   Updated: 2023/07/11 11:45:38 by manujime         ###   ########.fr       */
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
