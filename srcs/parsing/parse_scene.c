/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:33:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 08:46:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parse_scene(const char *filename, t_scene *rt_scene)
{
	if (check_extension(filename, ".rt"))
		return (1);
	if (check_reading_access(filename))
		return (1);
	if (count_elements(filename, rt_scene))
		return (1);
	if (alloc_structure(rt_scene, rt_scene->elements))
		return (1);
	if (fill_structure(rt_scene, filename))
	{
		free_structure(rt_scene, rt_scene->elements);
		return (1);
	}
	print_structure(rt_scene);
	return (0);
}
