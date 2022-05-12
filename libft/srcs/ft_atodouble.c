/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:49:22 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 20:36:53 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	to_double_error(bool *error)
{
	*error = true;
	return (0.0);
}

static double	get_partie_decimale(char *str, int *index, bool *error)
{
	double	partie_decimale;
	int		partie_decimale_len;
	int		i;
	char	*decimal;

	if (str[*index] == '\0')
		return (0.0);
	else if (str[(*index)++] != '.' || ft_isdigit(str[*index]) != 1)
		return (to_double_error(error));
	partie_decimale_len = 0;
	i = *index;
	while (str[i] != '\0' && ft_isdigit(str[i++]) == 1)
		partie_decimale_len++;
	if (partie_decimale_len > 9)
		return (to_double_error(error));
	decimal = ft_substr(str, *index, partie_decimale_len);
	if (!decimal)
		return (to_double_error(error));
	partie_decimale = (double)ft_atoi(decimal) / pow(10, ft_strlen(decimal));
	*index += partie_decimale_len;
	free(decimal);
	return (partie_decimale);
}

static double	get_partie_entiere(char *str, int *index, bool *error)
{
	double	partie_entiere;
	int		partie_entiere_len;
	int		i;
	char	*entier;

	if (!str || str[*index] == '\0')
		return (to_double_error(error));
	partie_entiere = 0.0;
	partie_entiere_len = 0;
	i = *index;
	while (str[i] != '\0' && ft_isdigit(str[i++]) == 1)
		partie_entiere_len++;
	if (partie_entiere_len > 9)
		return (to_double_error(error));
	entier = ft_substr(str, *index, partie_entiere_len);
	if (!entier)
		return (to_double_error(error));
	partie_entiere = ft_atoi(entier);
	free(entier);
	*index += partie_entiere_len;
	return (partie_entiere);
}

static double	get_signe(char *str, int *index, bool *error)
{
	double	signe;

	if (!str || str[0] == '\0')
		return (to_double_error(error));
	signe = 1.0;
	while (str[*index] != '\0' && (str[*index] == '+' || str[*index] == '-'))
	{
		if (str[*index] == '-')
			signe *= -1.0;
		(*index)++;
	}
	return (signe);
}

/* This function converts an array of char into a double,
 * it takes a pointer on the first char and the adress of a boolean,
 * if an error occurs, the value of error is set to true. */

double	ft_atodouble(char *str, bool *error)
{
	double	signe;
	double	partie_entiere;
	double	partie_decimale;
	int		index;

	*error = false;
	index = 0;
	signe = get_signe(str, &index, error);
	if (*error == true)
		return (0.0);
	partie_entiere = get_partie_entiere(str, &index, error);
	if (*error == true)
		return (0.0);
	partie_decimale = get_partie_decimale(str, &index, error);
	if (str[index] != '\0')
		*error = true;
	if (*error == true)
		return (0.0);
	return (signe * (partie_entiere + partie_decimale));
}
