/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 19:25:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	refresh(void *ptr)
{
	t_world	*world;

	world = ptr;
	raytracer(&world->obj_list, &world->obj_list.camera, &world->mlx);
	return (0);
}

int	key_handler(int keycode, t_world *world)
{
	if (keycode == ESC_KEY)
		close_window(world);
	else if (keycode == LEFT_KEY)
		world->obj_list.camera.position.x -= 1;
	else if (keycode == TOP_KEY)
		world->obj_list.camera.position.z -= 1;
	else if (keycode == RIGHT_KEY)
		world->obj_list.camera.position.x += 1;
	else if (keycode == BOTTOM_KEY)
		world->obj_list.camera.position.z += 1;
	else
		printf("KEYCODE = %d\n", keycode);
	refresh(world);
	return (0);
}
