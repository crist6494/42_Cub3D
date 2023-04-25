/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmarque <anmarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:07:27 by anmarque          #+#    #+#             */
/*   Updated: 2023/02/14 20:10:48 by anmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep_char(char c, char sep)
{
	return (c == sep || c == '\0');
}

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (is_sep_char(str[i + 1], c) && !is_sep_char(str[i], c))
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char c)
{
	int	i;

	i = 0;
	while (!is_sep_char(from[i], c))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (!is_sep_char(str[i + j], c))
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	int		words;

	if (!s)
		return (NULL);
	str = (char *)s;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	write_split(res, str, c);
	return (res);
}
