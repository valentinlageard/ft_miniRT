/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 19:40:58 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/16 20:52:21 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_cyls(t_cyl *cyl)
{
	t_cyl	*current;
	t_cyl	*next;

	current = cyl;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->orientation);
		free(current->color);
		free(current);
		current = next;
	}
}

void	free_planes(t_plane *plane)
{
	t_plane	*current;
	t_plane	*next;

	current = plane;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->orientation);
		free(current->color);
		free(current);
		current = next;
	}
}

void	free_spheres(t_sphere *sphere)
{
	t_sphere	*current;
	t_sphere	*next;

	current = sphere;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->color);
		free(current);
		current = next;
	}
}

void	free_squares(t_square *square)
{
	t_square	*current;
	t_square	*next;

	current = square;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->orientation);
		free(current->color);
		free(current);
		current = next;
	}
}

void	free_triangles(t_tri *tri)
{
	t_tri	*current;
	t_tri	*next;

	current = tri;
	while (current)
	{
		next = current->next;
		free(current->a);
		free(current->b);
		free(current->c);
		free(current->color);
		free(current);
		current = next;
	}
}