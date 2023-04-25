/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmarque <anmarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:06:03 by anmarque          #+#    #+#             */
/*   Updated: 2022/04/21 16:18:41 by anmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ret = malloc(sizeof(char));
		if (!ret)
			return (NULL);
		ret[0] = '\0';
	}
	else
	{
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		ret = malloc(sizeof(char) * (len + 1));
		if (!ret)
			return (NULL);
		i = 0;
		while (++i - 1 < len)
			ret[i - 1] = s[start + i - 1];
		ret[i - 1] = '\0';
	}
	return (ret);
}
