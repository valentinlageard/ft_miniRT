/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:33:34 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 15:56:03 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_filename(char *filename, t_prog *prog)
{
	unsigned int	fn_len;

	fn_len = ft_strlen(filename);
	if (filename[fn_len - 3] != '.'
		|| filename[fn_len - 2] != 'r'
		|| filename[fn_len - 1] != 't')
		error_quit(prog, -1);
}

int		check_resolution(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && (!(issdigit(words[1])) || ft_atoi(words[1]) < 1))
			return (0);
		if (i == 2 && (!(issdigit(words[2])) || ft_atoi(words[2]) < 1))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int		check_camera(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && !(issvec3norm(words[2])))
			return (0);
		if (i == 3 && (!(issdigit(words[3]))
		|| ft_atoi(words[3]) < 1
		|| ft_atoi(words[3]) > 180))
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		check_ambient(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && (!(issfloat(words[1]))
			|| ft_atof(words[1]) < 0
			|| ft_atof(words[1]) > 1))
			return (0);
		if (i == 2 && !(isscol(words[2])))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int		check_light(char **words)
{
	unsigned int	i;

	i = 1;
	while (words[i])
	{
		if (i == 1 && !(issvec3(words[1])))
			return (0);
		if (i == 2 && (!(issfloat(words[2]))
			|| ft_atof(words[2]) < 0
			|| ft_atof(words[2]) > 1))
			return (0);
		if (i == 3 && !(isscol(words[3])))
			return (0);
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}
