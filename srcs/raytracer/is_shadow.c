/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:42:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 13:04:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Opti : pour eviter calcul de racine carre, comparer si la distance entre 
 * le rayon secondaire et l'intersection au CARRE est inferieure a la distance
 * au CARRE entre le rayon et la lumiere
 */

bool	is_shadow(t_ray *second_ray, t_light *light, t_obj_list *obj_list)
{
	size_t	i;

	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(&obj_list->obj[i], second_ray))
		{
			if (pow(second_ray->t, 2.0)
				< norm_square(sub_vector(second_ray->position, light->position)))
				return (true);
		}
		i++;
	}
	return (false);
}
