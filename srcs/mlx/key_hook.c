/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 08:38:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_handler(int keycode, t_world *world)
{
	if (keycode == ESC_KEY)
		close_window(world);
	else if (keycode == 123)
		world->obj_list.light.position.x -= 1;
	else if (keycode == 124)
		world->obj_list.light.position.x += 1;
	else if (keycode == 125)
		world->obj_list.light.position.z += 1;
	else if (keycode == 126)
		world->obj_list.light.position.z -= 1;
	else
		printf("KEYCODE = %d\n", keycode);
	return (0);
}
