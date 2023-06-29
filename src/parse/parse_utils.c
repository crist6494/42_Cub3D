/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:39:52 by manujime          #+#    #+#             */
/*   Updated: 2023/06/29 11:57:32 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//prints a char **
void	ft_print_char_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putstr_fd(matrix[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

//initializes the comp struct in the game struct
void	ft_init_comp(t_game *game)
{
	game->comp = malloc(sizeof(t_comp));
	game->comp->file = NULL;
	game->comp->no_path = NULL;
	game->comp->so_path = NULL;
	game->comp->we_path = NULL;
	game->comp->ea_path = NULL;
	game->comp->f_rgb = NULL;
	game->comp->c_rgb = NULL;
	game->comp->map = NULL;
}
