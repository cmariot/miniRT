/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:53:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:46:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the norm of a vetor, aka it's length.
 * In mathematics, the double bar (||a||) notation indicates the
 * lentgh of a vector. */

extern inline double	norm(const t_v3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}
