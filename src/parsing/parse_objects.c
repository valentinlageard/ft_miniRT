/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:30 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/12 04:45:54 by vlageard         ###   ########.fr       */
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
	new_sph->radius = atof(words[2]) / 2.0;
	new_sph->color = word_to_color(words[3]);
	push_back_sphere(&(prog->spheres), new_sph);
	new_obj = new_object();
	new_obj->type = 's';
	new_obj->object = new_sph;
	push_back_object(&(prog->objects), new_obj);
	free(words);
}

void	parse_plane(char *line, t_prog *prog)
{
	char		**words;
	t_plane		*new_plane;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	new_plane = new_pl();
	new_plane->pos = word_to_vector3(words[1]);
	new_plane->orientation = word_to_vector3(words[2]);
	new_plane->color = word_to_color(words[3]);
	push_back_plane(&(prog->planes), new_plane);
	new_obj = new_object();
	new_obj->type = 'p';
	new_obj->object = new_plane;
	push_back_object(&(prog->objects), new_obj);
	free(words);
}

void	parse_triangle(char *line, t_prog *prog)
{
	char		**words;
	t_tri		*new_triangle;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	new_triangle = new_tri();
	new_triangle->a = word_to_vector3(words[1]);
	new_triangle->b = word_to_vector3(words[2]);
	new_triangle->c = word_to_vector3(words[3]);
	new_triangle->color = word_to_color(words[4]);
	push_back_tri(&(prog->triangles), new_triangle);
	new_obj = new_object();
	new_obj->type = 't';
	new_obj->object = new_triangle;
	push_back_object(&(prog->objects), new_obj);
	free(words);
}