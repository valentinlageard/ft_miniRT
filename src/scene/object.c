/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:17:25 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:33:22 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*new_object(void)
{
	t_object	*new_object;

	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new_object->next = NULL;
	return (new_object);
}

void		push_back_object(t_object **first_object, t_object *new_object)
{
	t_object	*tmp;

	if (*first_object == NULL)
		*first_object = new_object;
	else
	{
		tmp = *first_object;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_object;
	}
}

double		intersect_object(t_ray *ray, t_object *object)
{
	if (object->type == 's')
		return (intersect_sphere(ray, (t_sphere *)object->object));
	else if (object->type == 'p')
		return (intersect_plane(ray, (t_plane *)object->object));
	else if (object->type == 't')
		return (intersect_tri(ray, (t_tri *)object->object));
	else if (object->type == 'q')
		return (intersect_square(ray, (t_square *)object->object));
	else if (object->type == 'c')
		return (intersect_cyl(ray, (t_cyl *)object->object));
	else
		return (1000.0);
}

t_light_p	*get_light_p_object(t_ray *ray, t_object *object)
{
	if (object->type == 's')
		return (get_light_p_sphere(ray, object));
	else if (object->type == 'p')
		return (get_light_p_plane(ray, object));
	else if (object->type == 't')
		return (get_light_p_tri(ray, object));
	else if (object->type == 'q')
		return (get_light_p_square(ray, object));
	else if (object->type == 'c')
		return (get_light_p_cyl(ray, object));
	else
		return (NULL);
}

void		free_objects(t_object *object)
{
	t_object	*current;
	t_object	*next;

	current = object;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
