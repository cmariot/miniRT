/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:03:03 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:37:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Memory allocation of the structure depending the number of spheres,
 * cylinders and plans of the scene. */

int	alloc_structure(t_scene *rt_scene, t_counter elements)
{
	if (elements.nb_sphere)
	{
		rt_scene->sphere = malloc(elements.nb_sphere * sizeof(t_sphere));
		if (!rt_scene->sphere)
			return (rt_error("Memory allocation failed during the parsing.",
					true));
	}
	if (elements.nb_plan)
	{
		rt_scene->plan = malloc(elements.nb_plan * sizeof(t_plan));
		if (!rt_scene->plan)
			return (rt_error("Memory allocation failed during the parsing.",
					true));
	}
	if (elements.nb_cylinder)
	{
		rt_scene->cylinder
			= malloc(elements.nb_cylinder * sizeof(t_cylinder));
		if (!rt_scene->cylinder)
			return (rt_error("Memory allocation failed during the parsing.",
					true));
	}
	return (0);
}
