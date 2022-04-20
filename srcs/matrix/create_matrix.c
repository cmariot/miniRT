/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:49:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 19:23:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_matrix	create_matrix(size_t rows, size_t columns)
{
	t_matrix	m;
	size_t		i;

	m.rows = rows;
	m.columns = columns;
	m.matrix = ft_calloc(rows, sizeof(float *));
	if (m.matrix == NULL)
		return (m);
	i = 0;
	while (i < rows)
	{
		m.matrix[i] = ft_calloc(columns, sizeof(float));
		if (m.matrix == NULL)
			return (m);
		i++;
	}
	return (m);
}

t_matrix	matrix_multiplication(t_matrix m1, t_matrix m2)
{
	t_matrix	m;
	size_t		i;
	size_t		j;

	m.rows = m1.rows;
	m.columns = m1.columns;
	m.matrix = ft_calloc(m1.rows, sizeof(float *));
	if (m.matrix == NULL)
		return (m);
	i = 0;
	while (i < m1.rows)
	{
		m.matrix[i] = ft_calloc(m1.columns, sizeof(float));
		if (m.matrix == NULL)
			return (m);
		j = 0;
		while (j < m1.columns)
		{
			m.matrix[i][j] = m1.matrix[i][j] * m2.matrix[i][j];
			printf("%f ", m.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (m);
}
