/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:35:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 18:57:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	sub_vector(const t_v3 a, const t_v3 b)
{
	return (new_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}
