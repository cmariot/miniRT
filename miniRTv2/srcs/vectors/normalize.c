/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/30 19:29:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* A surface normal from a surface at P,
 * is a vector perpendicular to the tangent plane to that surface at P. */

t_3d	normalize(t_3d a)
{
	t_3d		b;
	double		norme;

	norme = norm(a);
	b.x = a.x / norme;
	b.y = a.y / norme;
	b.z = a.z / norme;
	return (b);
}
