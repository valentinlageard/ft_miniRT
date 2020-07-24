/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 15:51:29 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 15:57:27 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	issdigit(char *str)
{
	unsigned int	i;
	unsigned int	nmin;

	i = 0;
	nmin = 0;
	while (str[i])
	{
		if (!(str[i] == '-' || ft_isdigit(str[i])))
			return (0);
		if (str[i] == '-')
			nmin++;
		i++;
	}
	if (nmin > 1)
		return (0);
	return (1);
}

int	issfloat(char *str)
{
	unsigned int	i;
	unsigned int	strlen;
	unsigned int	ndot;
	unsigned int	nmin;

	i = 0;
	ndot = 0;
	nmin = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		if (!(ft_isdigit(str[i]) || str[i] == '.' || str[i] == '-'))
			return (0);
		if (str[i] == '.')
			ndot++;
		if (str[i] == '-')
			nmin++;
		i++;
	}
	if (ndot > 1 || nmin > 1)
		return (0);
	return (1);
}

int	issvec3(char *str)
{
	char			**words;
	unsigned int	i;

	words = ft_split(str, ",");
	i = 0;
	while (words[i])
	{
		if (!(issfloat(words[i])))
		{
			ft_free_words(words);
			return (0);
		}
		i++;
	}
	ft_free_words(words);
	if (i != 3)
		return (0);
	return (1);
}

int	issvec3norm(char *str)
{
	char			**words;
	unsigned int	i;

	words = ft_split(str, ",");
	i = 0;
	while (words[i])
	{
		if (!(issfloat(words[i]))
		|| ft_atof(words[i]) < -1
		|| ft_atof(words[i]) > 1)
		{
			ft_free_words(words);
			return (0);
		}
		i++;
	}
	ft_free_words(words);
	if (i != 3)
		return (0);
	return (1);
}

int	isscol(char *str)
{
	char			**words;
	unsigned int	i;
	int				col;

	words = ft_split(str, ",");
	i = 0;
	while (words[i])
	{
		if (!(issdigit(words[i])))
		{
			ft_free_words(words);
			return (0);
		}
		col = ft_atoi(words[i]);
		if (col < 0 || col > 255)
		{
			ft_free_words(words);
			return (0);
		}
		i++;
	}
	ft_free_words(words);
	if (i != 3)
		return (0);
	return (1);
}
