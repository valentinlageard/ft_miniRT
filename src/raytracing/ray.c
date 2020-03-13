/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:14 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/10 15:41:12 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	*new_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray	*new_ray;

	if(!(new_ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	new_ray->orig = origin;
	new_ray->dir = dir;
	return(new_ray);
}

void	free_ray(t_ray *ray)
{
	free(ray->orig);
	free(ray->dir);
	free(ray);
}