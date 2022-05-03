/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:43:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:45:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_sphere(t_obj sphere)
{
	printf("\nSphere :\n");
	printf("|\tPosition : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		sphere.position.x, sphere.position.y, sphere.position.z);
	printf("|\tDiameter : %.3f, Radius : %.3f\n",
		sphere.radius * 2, sphere.radius);
	printf("|\tColor    : (r = %d ; g = %d ; b = %d ; trgb = %d)\n\n",
		sphere.color.r, sphere.color.g, sphere.color.b, sphere.color.trgb);
}

void	print_plan(t_obj plan)
{
	printf("\nPlan :\n");
	printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		plan.position.x, plan.position.y, plan.position.z);
	printf("|\tDirection : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		plan.direction.x, plan.direction.y, plan.direction.z);
	printf("|\tColor     : (r = %d ; g = %d ; b = %d ; trgb = %d)\n\n",
		plan.color.r, plan.color.g, plan.color.b, plan.color.trgb);
}

void	print_cylinder(t_obj cylinder)
{
	printf("\nCylinder :\n");
	printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		cylinder.position.x, cylinder.position.y, cylinder.position.z);
	printf("|\tDirection : (x = %.3f ; y = %.3f ; z = %.3f))\n",
		cylinder.direction.x, cylinder.direction.y, cylinder.direction.z);
	printf("|\tRadius    : %.3f\n|\tHeight    : %.3f\n",
		cylinder.radius, cylinder.height);
	printf("|\tColor     : (r = %d ; g = %d ; b = %d ; trgb = %d)\n\n",
		cylinder.color.r, cylinder.color.g, cylinder.color.b,
		cylinder.color.trgb);
}

void	print_lights(t_light_list light_list, t_light *spot,
	t_obj_list *list_obj)
{
	size_t	i;

	printf("\nAmbient_light\n");
	printf("|\tColor     : (r = %d ; g = %d ; b = %d ; trgb = %d)\n",
		light_list.ambient.color.r, light_list.ambient.color.g,
		light_list.ambient.color.b, light_list.ambient.color.trgb);
	printf("|\tRatio     : %.3f\n\n", light_list.ambient.ratio);
	i = 0;
	while (i < list_obj->nb_spot_light)
	{
		printf("\nSpot_light\n");
		printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
			spot[i].position.x, spot[i].position.y,
			spot[i].position.z);
		printf("|\tColor     : (r = %d ; g = %d ; b = %d ; trgb = %d)\n",
			spot[i].color.r, spot[i].color.g,
			spot[i].color.b, spot[i].color.trgb);
		printf("|\tRatio     : %.3f\n\n", spot[i].ratio);
		i++;
	}
}

void	print_structure(t_world *world, t_obj_list *objs_list)
{
	size_t	i;

	i = 0;
	while (i < world->obj_list.nb_camera)
	{
		printf("\nCamera : \n");
		printf("|\tPosition  : (x = %.3f ; y = %.3f ; z = %.3f))\n",
			world->camera[i].position.x, world->camera[i].position.y,
			world->camera[i].position.z);
		printf("|\tDirection : (x = %.3f ; y = %.3f ; z = %.3f))\n",
			world->camera[i].direction.x, world->camera[i].direction.y,
			world->camera[i].direction.z);
		printf("|\tFOV horizontal = %.3f ; FOV vertical = %.3f\n\n",
			world->camera[i].fov_horizontal, world->camera[i].fov_vertical);
		i++;
	}
	print_lights(world->light_list, world->light_list.spot_light,
		&world->obj_list);
	i = 0;
	while (i < world->obj_list.nb_objs)
	{
		objs_list->objs[i].print(objs_list->objs[i]);
		i++;
	}
}
