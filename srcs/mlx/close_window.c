/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 18:09:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_window(t_scene *scene)
{
	free_structure(scene, scene->elements);
	mlx_clear_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
	mlx_destroy_window(scene->mlx.mlx_ptr, scene->mlx.win_ptr);
//	mlx_destroy_display(scene->mlx.mlx_ptr);
	free(scene->mlx.mlx_ptr);
	exit(EXIT_SUCCESS);
	return (1);
}
