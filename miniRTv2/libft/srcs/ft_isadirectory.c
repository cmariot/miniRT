/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isadirectory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:52:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 10:27:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Check if path is a directory */

bool	ft_isadirectory(char *path)
{
	DIR	*fd_dir;

	fd_dir = opendir(path);
	if (fd_dir == NULL)
	{
		return (false);
	}
	else
	{
		closedir(fd_dir);
		return (true);
	}
}
