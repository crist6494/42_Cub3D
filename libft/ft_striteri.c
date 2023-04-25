/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmarque <anmarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:08:55 by anmarque          #+#    #+#             */
/*   Updated: 2022/04/26 17:23:51 by anmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	j;

	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		j = 0;
		while (j < i)
		{
			(*f)(j, s);
			s++;
			j++;
		}
	}
}
