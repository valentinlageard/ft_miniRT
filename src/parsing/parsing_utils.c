/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:54 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/15 19:38:56 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*word_to_vector3(char *word)
{
	char		**components;
	t_vec3	*new_vec3;

	components = ft_split(word, ",");
	if (!(new_vec3 = (t_vec3 *)malloc(sizeof(t_vec3))))
		return (NULL);	
	new_vec3->x = ft_atof(components[0]);
	new_vec3->y = ft_atof(components[1]);
	new_vec3->z = ft_atof(components[2]);
	ft_free_words(components);
	return (new_vec3);
}

t_color		*word_to_color(char *word)
{
	char	**components;
	t_color	*new_color;

	components = ft_split(word, ",");
	if (!(new_color = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	new_color->red = ft_atoi(components[0]);
	new_color->green = ft_atoi(components[1]);
	new_color->blue = ft_atoi(components[2]);
	ft_free_words(components);
	return (new_color);
}