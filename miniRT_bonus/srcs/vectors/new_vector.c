/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:10:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:46:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	new_vector(const double x, const double y, const double z)
{
	t_v3	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
