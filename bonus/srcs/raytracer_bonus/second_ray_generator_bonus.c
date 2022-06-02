/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_ray_generator_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:43:50 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:45:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/*
 * Origine   : point d'intersection de first_ray avec objet
 *             On décale legerement l'origine du vecteur pour supprimer le bruit
 * Direction : Lumiere
 */

t_ray	second_ray_generator(t_ray *first_ray, t_light *light)
{
	t_ray			second_ray;
	t_v3			decalage;
	const double	epsilon = 0.0001;

	decalage = multiply(first_ray->normale, epsilon);
	second_ray.position = add(first_ray->intersection, decalage);
	second_ray.direction
		= normalize(sub(light->position, first_ray->intersection));
	return (second_ray);
}
