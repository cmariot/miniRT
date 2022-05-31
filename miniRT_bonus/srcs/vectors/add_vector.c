/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:28:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/31 09:12:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	add(const t_v3 a, const t_v3 b)
{
	return (new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

extern inline t_v3	add_lvalue(const t_v3 *a, const t_v3 *b)
{
	return (new_vector(a->x + b->x, a->y + b->y, a->z + b->z));
}
