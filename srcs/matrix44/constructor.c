/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:20:36 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/06 16:42:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_44.h"
#include <stdio.h>

void	print_matrix(t_mat matrix, char *matrix_name)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	printf("%s :\n", matrix_name);
	cols = 4;
	rows = 4;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (j < cols - 1)
				printf("%f | ", matrix.m44[i][j]);
			else
				printf("%f\n", matrix.m44[i][j]);
			j++;
		}
		i++;
	}
}

t_mat	matrix_product(t_mat m1, t_mat m2)
{
	t_mat	new;
	int		rows;
	int		cols;
	int		i;
	int		j;

	cols = 4;
	rows = 4;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			new.m44[i][j++] = 0;
		i++;
	}
	return (new);
}

void	init_matrix(t_mat *matrix, float value)
{
	int	rows;
	int	cols;
	int	i;
	int	j;

	cols = 4;
	rows = 4;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
			matrix->m44[i][j++] = value;
		i++;
	}
}

int	main(void)
{
	t_mat	test;

	init_matrix(&test, 0);
	print_matrix(test, "TEST");
	return (0);
}
