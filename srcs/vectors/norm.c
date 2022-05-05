/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:53:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 21:48:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Return the norm of a vetor, aka it's length.
 * In mathematics, the double bar (||a||) notation indicates the
 * lentgh of a vector. */

double	norm(t_3d a)
{
	return (sqrt(norm_square(a)));
}
