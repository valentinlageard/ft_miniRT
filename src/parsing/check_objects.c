/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:50:25 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 15:57:19 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_sphere(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && (!(issfloat(words[2])) || ft_atof(words[2]) < 0))
			return (0);
		if (i == 3 && !(isscol(words[3])))
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int	check_plane(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && !(issvec3norm(words[2])))
			return (0);
		if (i == 3 && !(isscol(words[3])))
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int	check_triangle(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && !(issvec3(words[2])))
			return (0);
		if (i == 3 && !(issvec3(words[3])))
			return (0);
		if (i == 4 && !(isscol(words[4])))
			return (0);
		i++;
	}
	if (i != 5)
		return (0);
	return (1);
}

int	check_square(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && !(issvec3norm(words[2])))
			return (0);
		if (i == 3 && (!(issfloat(words[3])) || ft_atof(words[3]) < 0))
			return (0);
		if (i == 4 && !(isscol(words[4])))
			return (0);
		i++;
	}
	if (i != 5)
		return (0);
	return (1);
}

int	check_cyl(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && !(issvec3norm(words[2])))
			return (0);
		if (i == 3 && (!(issfloat(words[3])) || ft_atof(words[3]) < 0))
			return (0);
		if (i == 4 && (!(issfloat(words[4])) || ft_atof(words[4]) < 0))
			return (0);
		if (i == 5 && !(isscol(words[5])))
			return (0);
		i++;
	}
	if (i != 6)
		return (0);
	return (1);
}
