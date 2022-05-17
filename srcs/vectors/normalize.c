/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 15:19:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* A surface normal from a surface at P,
 * is a vector perpendicular to the tangent plane to that surface at P. */

t_v3	normalize(t_v3 a)
{
	double		norme;

	norme = norm(a);
	return (new_vector(a.x / norme, a.y / norme, a.z / norme));
}
