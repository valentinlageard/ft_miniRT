/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:54 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 17:47:54 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector3	*word_to_vector3(char *word)
{
	char		**components;
	t_vector3	*new_vector3;
	
	components = ft_split(word, ",");
	if (!(new_vector3 = (t_vector3 *)malloc(sizeof(t_vector3))))
		return (NULL);	
	new_vector3->x = ft_atof(components[0]);
	new_vector3->y = ft_atof(components[1]);
	new_vector3->z = ft_atof(components[2]);
	return (new_vector3);
}