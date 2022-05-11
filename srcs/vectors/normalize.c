/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 16:32:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* A surface normal from a surface at P,
 * is a vector perpendicular to the tangent plane to that surface at P. */

t_v3	normalize(t_v3 a)
{
	t_v3		b;
	double		norme;

	norme = norm(a);
	b.x = a.x / norme;
	b.y = a.y / norme;
	b.z = a.z / norme;
	return (b);
}
