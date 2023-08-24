/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:05:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/08/23 21:44:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_void(void)
{
	system("leaks -q Cub3D");
}

int	print_error(char *msg)
{
	printf("%s%s", ERROR_MSG, msg);
	return (-1);
}

void	error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

float	grades_to_rad(float angle)
{
	float	res;

	res = (angle * M_PI) / 180;
	return (res);
}

float	normalize_angle(float angle)
{
	if (angle < 0)
		angle = 360 + angle;
	else if (angle > 360)
		angle = angle - 360;
	return (angle);
}
