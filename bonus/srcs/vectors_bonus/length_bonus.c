/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:28:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 22:58:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

/* Return the distance between two points, a and b,
 * which have 3d positions */

extern inline double	length(const t_v3 a, const t_v3 b)
{
	return (norm(sub(b, a)));
}

extern inline double	length_lvalue(const t_v3 *a, const t_v3 *b)
{
	return (norm(sub_lvalue(b, a)));
}
