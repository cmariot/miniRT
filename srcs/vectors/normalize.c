/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:57:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* A surface normal from a surface at P,
 * is a vector perpendicular to the tangent plane to that surface at P. */

extern inline t_v3	normalize(const t_v3 a)
{
	float		norme;

	norme = norm(a);
	return (new_vector(a.x / norme, a.y / norme, a.z / norme));
}
