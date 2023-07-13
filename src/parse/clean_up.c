/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:59:59 by manujime          #+#    #+#             */
/*   Updated: 2023/07/13 20:45:36 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_exit_parse_error(t_comp *comp)
{
	printf("Error\n");
	ft_free_char_matrix(comp->file);
	free(comp->no_path);
	free(comp->so_path);
	free(comp->we_path);
	free(comp->ea_path);
	free(comp->f_rgb);
	free(comp->c_rgb);
	if (comp->no != NULL)
		mlx_delete_texture(comp->no);
	if (comp->so != NULL)
		mlx_delete_texture(comp->so);
	if (comp->we != NULL)
		mlx_delete_texture(comp->we);
	if (comp->ea != NULL)
		mlx_delete_texture(comp->ea);
	free(comp);
	exit(1);
}
