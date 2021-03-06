/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:01:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/12 08:54:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	memory_allocation(t_obj_list *obj_list)
{
	if (obj_list->nb_obj)
	{
		obj_list->obj = ft_calloc(sizeof(t_obj), obj_list->nb_obj);
		if (!obj_list->obj)
			return (rt_error("Memory allocation failed."));
	}
	return (0);
}
