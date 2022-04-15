/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:59:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 12:24:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* This functions file counts the elements to display on the screen.
 * The file is open and the structure variables are set to default,
 * next the file is read, we get its content with get_next_line and split.
 * The number of each elements is set in the t_scene structure.
 * If there is not or more than one ambient_light, camera and light it's an
 * error. */

int	check_nb_elements(t_scene *rt_scene)
{
	if (rt_scene->elements.nb_ambient_light != 1)
		return (rt_error("The scene must have one ambient light."));
	else if (rt_scene->elements.nb_camera != 1)
		return (rt_error("The scene must have one camera."));
	else if (rt_scene->elements.nb_light != 1)
		return (rt_error("The scene must have one light."));
	return (0);
}

int	get_element_type(char *line, t_scene *rt_scene)
{
	char	**splitted_line;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("Could not split the line."));
	if (ft_strcmp(splitted_line[0], "A") == 0)
		rt_scene->elements.nb_ambient_light++;
	else if (ft_strcmp(splitted_line[0], "C") == 0)
		rt_scene->elements.nb_camera++;
	else if (ft_strcmp(splitted_line[0], "L") == 0)
		rt_scene->elements.nb_light++;
	else if (ft_strcmp(splitted_line[0], "sp") == 0)
		rt_scene->elements.nb_sphere++;
	else if (ft_strcmp(splitted_line[0], "pl") == 0)
		rt_scene->elements.nb_plan++;
	else if (ft_strcmp(splitted_line[0], "cy") == 0)
		rt_scene->elements.nb_cylinder++;
	else if (splitted_line[0] != NULL)
	{
		ft_free_array(splitted_line);
		return (rt_error("Unknown object in the scene file."));
	}
	ft_free_array(splitted_line);
	return (0);
}

void	init_scene(t_scene *rt_scene)
{
	rt_scene->elements.nb_ambient_light = 0;
	rt_scene->elements.nb_camera = 0;
	rt_scene->elements.nb_light = 0;
	rt_scene->elements.nb_sphere = 0;
	rt_scene->elements.nb_plan = 0;
	rt_scene->elements.nb_cylinder = 0;
	rt_scene->elements.index_sphere = 0;
	rt_scene->elements.index_plan = 0;
	rt_scene->elements.index_cylinder = 0;
	rt_scene->sphere = NULL;
	rt_scene->plan = NULL;
	rt_scene->cylinder = NULL;
}

int	count_elements(const char *filename, t_scene *rt_scene)
{
	int		file_descriptor;
	char	*line;
	bool	error;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("Could not open the scene."));
	init_scene(rt_scene);
	error = false;
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (error == false && get_element_type(line, rt_scene))
			error = true;
		free(line);
	}
	close(file_descriptor);
	if (error == true || check_nb_elements(rt_scene))
		return (1);
	return (0);
}
