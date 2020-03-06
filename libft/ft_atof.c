/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:57:57 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 17:03:13 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	first_part;
	double	second_part;
	size_t	i;
	size_t	len;
	
	i = 0;
	first_part = (double)ft_atoi(str);
	second_part = 0;
	while (str[i] != '.' && str[i])
		i++;
	if (str[i] == '.')
		i++;
	if (i != ft_strlen(str))
	{
		second_part = (double)ft_atoi(str + i);
		len = ft_strlen(str + i);
		while (len--)
		second_part /= 10;	
	}
	return (first_part + ((first_part > 0) ? second_part : -second_part));
}