/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:30 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 18:57:12 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_sphere(char *line, t_prog *prog)
{
	char		**words;
	t_sphere	*new_sph;

	words = ft_split(line, "\t ");
	new_sph = new_sphere();
	new_sph->pos = word_to_vector3(words[1]);
	new_sph->radius = atof(words[2]);
	new_sph->color = word_to_color(words[3]);
	push_back_sphere(&(prog->spheres), new_sph);
}