/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:10:18 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 14:52:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_3d	new_vector(float x, float y, float z)
{
	t_3d	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}