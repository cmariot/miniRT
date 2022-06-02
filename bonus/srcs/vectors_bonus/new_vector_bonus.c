/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:10:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 11:43:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

extern inline t_v3	new_vector(const double x, const double y, const double z)
{
	t_v3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.a = 1;
	return (new);
}
