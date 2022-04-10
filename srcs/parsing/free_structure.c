/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:29:31 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/08 16:14:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_structure(t_scene *rt_scene, t_counter elements)
{
	if (elements.nb_sphere && rt_scene->sphere)
		free(rt_scene->sphere);
	if (elements.nb_plan && rt_scene->plan)
		free(rt_scene->plan);
	if (elements.nb_cylinder && rt_scene->cylinder)
		free(rt_scene->cylinder);
}
