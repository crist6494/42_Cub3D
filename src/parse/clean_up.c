/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:59:59 by manujime          #+#    #+#             */
/*   Updated: 2023/07/14 19:53:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_paths(t_comp *comp)
{
	if (comp->no_path != NULL)
		free(comp->no_path);
	if (comp->so_path != NULL)
		free(comp->so_path);
	if (comp->we_path != NULL)
		free(comp->we_path);
	if (comp->ea_path != NULL)
		free(comp->ea_path);
	if (comp->f_rgb != NULL)
		free(comp->f_rgb);
	if (comp->c_rgb != NULL)
		free(comp->c_rgb);
}

void	ft_free_textures(t_comp *comp)
{
	if (comp->no != NULL)
		mlx_delete_texture(comp->no);
	if (comp->so != NULL)
		mlx_delete_texture(comp->so);
	if (comp->we != NULL)
		mlx_delete_texture(comp->we);
	if (comp->ea != NULL)
		mlx_delete_texture(comp->ea);
}

void	ft_exit_parse_error(t_comp *comp)
{
	ft_free_char_matrix(comp->file);
	ft_free_paths(comp);
	ft_free_textures(comp);
	free(comp);
	exit(1);
}
