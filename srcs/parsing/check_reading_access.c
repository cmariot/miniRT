/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reading_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:59:43 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/07 19:07:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* This function check if the file given as argument can be open and 
 * if we can read its content. If an error occurs, the program will stop. */

int	check_reading_access(const char *filename)
{
	int		file_descriptor;
	ssize_t	read_return;
	char	buf[1];

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (rt_error("Could not open the scene."));
	read_return = read(file_descriptor, buf, 1);
	close(file_descriptor);
	if (read_return == -1)
		return (rt_error("Could not read the scene."));
	return (0);
}
