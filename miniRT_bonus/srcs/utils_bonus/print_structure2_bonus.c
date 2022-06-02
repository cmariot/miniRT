/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 23:13:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 15:42:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	print_light(void *ptr)
{
	t_light	*light;

	light = (t_light *)ptr;
	printf("\nLight\n");
	printf("|\tPosition  : x = %.3f ; y = %.3f ; z = %.3f\n",
		light->position.x,
		light->position.y,
		light->position.z);
	printf("|\tRatio     : %.3f\n\n",
		light->ratio);
}

void	print_ambient(void *ptr)
{
	t_amb	*ambient;

	ambient = (t_amb *)ptr;
	printf("\nAmbient Light\n");
	printf("|\tColor     : r = %.f ; g = %.f ; b = %.f ; trgb = %d\n",
		ambient->color.r,
		ambient->color.g,
		ambient->color.b,
		ambient->color.trgb);
	printf("|\tRatio     : %.3f\n\n",
		ambient->ratio);
}

void	print_camera(void *ptr)
{
	t_cam	*camera;

	camera = (t_cam *)ptr;
	printf("\nCamera : \n");
	printf("|\tPosition  : x = %.3f ; y = %.3f ; z = %.3f\n",
		camera->position.x,
		camera->position.y,
		camera->position.z);
	printf("|\tDirection : x = %.3f ; y = %.3f ; z = %.3f\n",
		camera->direction.x,
		camera->direction.y,
		camera->direction.z);
	printf("|\tFOV hori  : %f\n",
		camera->fov_horizontal);
	printf("\n");
}
