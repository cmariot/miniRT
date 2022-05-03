/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_object_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:22:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 09:19:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* This functions file counts the elements to display on the screen.
 * The file is open and the structure variables are set to default,
 * next the file is read, we get its content with get_next_line and split.
 * The number of each elements is set in the t_world structure.
 * If there is not or more than one ambient_light, camera and light it's an
 * error. */

int	check_nb_elements(t_obj_list *obj_list)
{
	if (obj_list->nb_ambient_light != 1)
		return (rt_error("The scene must have one ambient light."));
	else if (obj_list->nb_camera != 1)
		return (rt_error("The scene must have one camera."));
	else if (obj_list->nb_spot_light != 1)
		return (rt_error("The scene must have one light."));
	return (0);
}

int	get_element_type(t_obj_list *obj_list, char *line)
{
	char	**splitted_line;

	splitted_line = ft_split(line, ' ');
	if (!splitted_line)
		return (rt_error("Could not split the line."));
	if (ft_strcmp(splitted_line[0], "sp") == 0
		|| ft_strcmp(splitted_line[0], "pl") == 0
		|| ft_strcmp(splitted_line[0], "cy") == 0)
		obj_list->nb_objs++;
	else if (ft_strcmp(splitted_line[0], "A") == 0)
		obj_list->nb_ambient_light++;
	else if (ft_strcmp(splitted_line[0], "C") == 0)
		obj_list->nb_camera++;
	else if (ft_strcmp(splitted_line[0], "L") == 0)
		obj_list->nb_spot_light++;
	else if (splitted_line[0] != NULL)
	{
		ft_free_array(splitted_line);
		return (rt_error("Unknown object in the scene file."));
	}
	ft_free_array(splitted_line);
	return (0);
}

void	set_initial_values(t_obj_list *obj_list)
{
	obj_list->nb_camera = 0;
	obj_list->nb_objs = 0;
	obj_list->nb_spot_light = 0;
	obj_list->nb_ambient_light = 0;
}

int	get_object_list(t_obj_list *obj_list, const char *filename)
{
	int		file_descriptor;
	char	*line;
	bool	error;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("Could not open the scene."));
	set_initial_values(obj_list);
	error = false;
	while (1)
	{
		line = gnl_without_bn(file_descriptor);
		if (!line)
			break ;
		if (error == false && get_element_type(obj_list, line))
			error = true;
		free(line);
	}
	close(file_descriptor);
	if (error == true || check_nb_elements(obj_list))
		return (1);
	return (0);
}
