/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 23:17:25 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/18 00:22:54 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_object	*new_object(void)
{
	t_object	*new_object;
	
	if (!(new_object = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new_object->next = NULL;
	return(new_object);
}

void	push_back_object(t_object **first_object, t_object *new_object)
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

t_light_p	*get_light_p_object(t_ray *ray, t_object *object)
{
	if (object->type == 's')
		return (get_light_p_sphere(ray, object));
	else
		return (NULL);
}
