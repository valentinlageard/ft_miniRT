/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:30 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/26 18:19:00 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_sphere(char *line, t_prog *prog)
{
	char		**words;
	t_sphere	*new_sph;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	if (!(check_sphere(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		printf("sphere error\n");
		return;
	}
	new_sph = new_sphere();
	new_sph->pos = word_to_vector3(words[1]);
	new_sph->radius = ft_atof(words[2]) / 2.0;
	new_sph->color = word_to_color(words[3]);
	push_back_sphere(&(prog->spheres), new_sph);
	new_obj = new_object();
	new_obj->type = 's';
	new_obj->object = new_sph;
	push_back_object(&(prog->objects), new_obj);
	ft_free_words(words);
}

void	parse_plane(char *line, t_prog *prog)
{
	char		**words;
	t_plane		*new_plane;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	if (!(check_plane(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		printf("plane error\n");
		return;
	}
	new_plane = new_pl();
	new_plane->pos = word_to_vector3(words[1]);
	new_plane->orientation = word_to_vector3(words[2]);
	new_plane->color = word_to_color(words[3]);
	push_back_plane(&(prog->planes), new_plane);
	new_obj = new_object();
	new_obj->type = 'p';
	new_obj->object = new_plane;
	push_back_object(&(prog->objects), new_obj);
	ft_free_words(words);
}

void	parse_triangle(char *line, t_prog *prog)
{
	char		**words;
	t_tri		*new_triangle;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	if (!(check_triangle(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		printf("triangle error\n");
		return;
	}
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
	ft_free_words(words);
}

void	parse_square(char *line, t_prog *prog)
{
	char		**words;
	t_square	*new_square;
	t_object	*new_obj;

	words = ft_split(line, "\t ");
	if (!(check_square(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		printf("square error\n");
		return;
	}
	new_square = new_sq();
	new_square->pos = word_to_vector3(words[1]);
	new_square->orientation = word_to_vector3(words[2]);
	new_square->size = ft_atof(words[3]);
	new_square->color = word_to_color(words[4]);
	push_back_square(&(prog->squares), new_square);
	new_obj = new_object();
	new_obj->type = 'q';
	new_obj->object = new_square;
	push_back_object(&(prog->objects), new_obj);
	ft_free_words(words);
}

void	parse_cyl(char *line, t_prog *prog)
{
	char		**words;
	t_cyl		*new_cylinder;
	t_object	*new_obj;
	
	words = ft_split(line, "\t ");
	if (!(check_cyl(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		printf("cyl error\n");
		return;
	}
	new_cylinder = new_cyl();
	new_cylinder->pos = word_to_vector3(words[1]);
	new_cylinder->orientation = word_to_vector3(words[2]);
	new_cylinder->diameter = ft_atof(words[3]);
	new_cylinder->size = ft_atof(words[4]);
	new_cylinder->color = word_to_color(words[5]);
	push_back_cyl(&(prog->cylinders), new_cylinder);
	new_obj = new_object();
	new_obj->type = 'c';
	new_obj->object = new_cylinder;
	push_back_object(&(prog->objects), new_obj);
	ft_free_words(words);
}