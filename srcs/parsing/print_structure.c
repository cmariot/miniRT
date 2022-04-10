/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:17:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/09 10:41:34 by cmariot          ###   ########.fr       */
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
		printf("\tCenter : %f, %f, %f\n", cylinder[i].center.x,
			cylinder[i].center.y, cylinder[i].center.z);
		printf("\tOrientation : %f, %f, %f\n", cylinder[i].orientation.x,
			cylinder[i].orientation.y, cylinder[i].orientation.z);
		printf("\tDiameter : %f\n", cylinder[i].diameter);
		printf("\tHeigth : %f\n", cylinder[i].heigth);
		printf("\tColor RGB : %d\n\n", cylinder[i].color);
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
		printf("\tCenter : %f, %f, %f\n", plan[i].center.x,
			plan[i].center.y, plan[i].center.z);
		printf("\tOrientation : %f, %f, %f\n", plan[i].orientation.x,
			plan[i].orientation.y, plan[i].orientation.z);
		printf("\tColor RGB : %d\n\n", plan[i].color);
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
		printf("\tCenter : %f, %f, %f\n", sphere[i].center.x,
			sphere[i].center.y, sphere[i].center.z);
		printf("\tDiameter : %f\n", sphere[i].diameter);
		printf("\tColor RGB : %d\n\n", sphere[i].color);
		i++;
	}
}

/* Ambient light, Camera and Light */

void	print_main_elements(t_scene *rt_scene)
{
	print(1, "Ambient light :\n");
	printf("\tRatio : %f\n", rt_scene->ambient_light.ratio);
	printf("\tColor RGB : %d\n\n", rt_scene->ambient_light.color);
	print(1, "Camera :\n");
	printf("\tPOV coordinates : %f, %f, %f\n", rt_scene->camera.pov.x,
		rt_scene->camera.pov.y, rt_scene->camera.pov.z);
	printf("\tOrientation vector : %f, %f, %f\n", rt_scene->camera.orientation.x,
		rt_scene->camera.orientation.y, rt_scene->camera.orientation.z);
	printf("\tFOV : %f\n\n", rt_scene->camera.fov);
	print(1, "Light :\n");
	printf("\tPOL coordinates : %f, %f, %f\n", rt_scene->light.point.x,
		rt_scene->light.point.y, rt_scene->light.point.z);
	printf("\tRatio : %f\n", rt_scene->light.ratio);
	printf("\tColor RGB : %d\n\n", rt_scene->light.color);
}

void	print_structure(t_scene *rt_scene)
{
	print_main_elements(rt_scene);
	print_spheres(rt_scene, rt_scene->sphere);
	print_plans(rt_scene, rt_scene->plan);
	print_cylinders(rt_scene, rt_scene->cylinder);
}
