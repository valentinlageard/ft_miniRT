/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:30 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/14 20:28:09 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_sphere(char *line, t_prog *prog)
{
	char		**words;
	t_sphere	*new_sph;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	new_sph = new_sphere();
	new_sph->pos = word_to_vector3(words[1]);
	printf("sp->pos : ");
	print_vec3(new_sph->pos);
	new_sph->radius = atof(words[2]) / 2.0;
	printf("sp->radius : %f\n", new_sph->radius);
	new_sph->color = word_to_color(words[3]);
	printf("sp->color : r%i g%i b%i\n", new_sph->color->red,new_sph->color->green,new_sph->color->blue);
	push_back_sphere(&(prog->spheres), new_sph);
	new_obj = new_object();
	new_obj->type = 's';
	new_obj->object = new_sph;
	push_back_object(&(prog->objects), new_obj);
}