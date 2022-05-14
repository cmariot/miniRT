/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:41:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/14 12:23:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Pour chaque objet de la liste, si le rayon traverse l'objet et
 * si la distance entre la camera et cet objet est inferieure à celle
 * des precedents objets on calcule la couleur du pixel
 */

int	check_intersection(t_ray *first_ray, t_obj_list *obj_list)
{
	size_t	i;
	double	max_distance;
	int		color;
	t_ray	second_ray;

	i = 0;
	max_distance = INFINITY;
	color = illumination(obj_list->ambient.color, *obj_list, *first_ray);
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(obj_list->obj[i], first_ray))
		{
			if (first_ray->t < max_distance)
			{
				max_distance = first_ray->t;
				second_ray = second_ray_generator(first_ray, obj_list->light);
				if (is_shadow(&second_ray, obj_list->light, obj_list))
					color = illumination(obj_list->obj[i].color, *obj_list, second_ray);
				else
					color = illumination(obj_list->obj[i].color, *obj_list, *first_ray);
			}
		}
		i++;
	}
	return (color);
}
