/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:34:42 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:36:45 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(void)
{
	t_sphere	*new_sphere;

	if (!(new_sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	new_sphere->next = NULL;
	return (new_sphere);
}

void	push_back_sphere(t_sphere **first_sphere, t_sphere *new_sphere)
{
	t_sphere	*tmp;

	if (*first_sphere == NULL)
		*first_sphere = new_sphere;
	else
	{
		tmp = *first_sphere;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_sphere;
	}
}
