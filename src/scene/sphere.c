/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:34:42 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 16:15:39 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*new_sphere(void)
{
	t_sphere	*new_sphere;
	
	if (!(new_sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	new_sphere->next = NULL;
	return(new_sphere);
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

double	intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec3	*oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub(ray->orig, sphere->pos);
	a = vec3_dot(ray->dir, ray->dir);
	b = 2 * vec3_dot(ray->dir,oc);
	c = vec3_dot(oc, oc) - sphere->radius*sphere->radius;
	free(oc);
	return (get_min_quadratic_solution(a, b, c));
}