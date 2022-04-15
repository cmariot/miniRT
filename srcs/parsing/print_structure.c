/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:17:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 09:07:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Display the structure elements on STDOUT, used to debug */

void	print_cylinders(t_scene *rt_scene, t_cylinder *cylinder)
{
	unsigned int	i;

	i = 0;
	while (i < rt_scene->elements.nb_cylinder)
	{
		printf("Cylinder[%d] :\n", i);
		printf("\tCenter : %f, %f, %f\n", cylinder[i].point.x,
			cylinder[i].point.y, cylinder[i].point.z);
		printf("\tOrientation : %f, %f, %f\n", cylinder[i].direction.x,
			cylinder[i].direction.y, cylinder[i].direction.z);
		printf("\tDiameter : %f\n", cylinder[i].diameter);
		printf("\tHeigth : %f\n", cylinder[i].heigth);
		i++;
	}
}

void	print_plans(t_scene *rt_scene, t_plan *plan)
{
	unsigned int	i;

	i = 0;
	while (i < rt_scene->elements.nb_plan)
	{
		printf("Plan[%d] :\n", i);
		printf("\tCenter : %f, %f, %f\n", plan[i].point.x,
			plan[i].point.y, plan[i].point.z);
		printf("\tOrientation : %f, %f, %f\n", plan[i].direction.x,
			plan[i].direction.y, plan[i].direction.z);
		i++;
	}
}

void	print_spheres(t_scene *rt_scene, t_sphere *sphere)
{
	unsigned int	i;

	i = 0;
	while (i < rt_scene->elements.nb_sphere)
	{
		printf("Sphere[%d] :\n", i);
		printf("\tCenter : %f, %f, %f\n", sphere[i].point.x,
			sphere[i].point.y, sphere[i].point.z);
		printf("\tDiameter : %f\n", sphere[i].diameter);
		i++;
	}
}

/* Ambient light, Camera and Light */

void	print_main_elements(t_scene *rt_scene)
{
	print(1, "Ambient light :\n");
	printf("\tRatio : %f\n", rt_scene->ambient_light.ratio);
	print(1, "Camera :\n");
	printf("\tPOV coordinates : %f, %f, %f\n", rt_scene->camera.point.x,
		rt_scene->camera.point.y, rt_scene->camera.point.z);
	printf("\tOrientation vector : %f, %f, %f\n", rt_scene->camera.direction.x,
		rt_scene->camera.direction.y, rt_scene->camera.direction.z);
	printf("\tFOV : %f\n\n", rt_scene->camera.fov);
	print(1, "Light :\n");
	printf("\tPOL coordinates : %f, %f, %f\n", rt_scene->light.point.x,
		rt_scene->light.point.y, rt_scene->light.point.z);
	printf("\tRatio : %f\n", rt_scene->light.ratio);
}

void	print_structure(t_scene *rt_scene)
{
	print_main_elements(rt_scene);
	print_spheres(rt_scene, rt_scene->sphere);
	print_plans(rt_scene, rt_scene->plan);
	print_cylinders(rt_scene, rt_scene->cylinder);
}
