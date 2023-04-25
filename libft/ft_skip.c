/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmarque <anmarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:14:20 by anmarque          #+#    #+#             */
/*   Updated: 2023/02/07 21:51:42 by anmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isin(int c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_skip_char(const char *str, int *i, char c)
{
	while (str[*i] == c)
		(*i)++;
}

void	ft_skip_chars(const char *str, int *i, char *base)
{
	while (ft_isin(str[*i], base))
		(*i)++;
}

void	ft_skip_space(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t')
		|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
			(*i)++;
}

void	ft_skip_spacenl(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}
