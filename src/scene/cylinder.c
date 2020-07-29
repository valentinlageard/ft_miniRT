/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:33:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 19:47:43 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cyl	*new_cyl(void)
{
	t_cyl	*new_cyl;

	if (!(new_cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (NULL);
	new_cyl->next = NULL;
	return (new_cyl);
}

void	push_back_cyl(t_cyl **first_cyl, t_cyl *new_cyl)
{
	t_cyl	*tmp;

	if (*first_cyl == NULL)
		*first_cyl = new_cyl;
	else
	{
		tmp = *first_cyl;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cyl;
	}
}

t_vec3	*get_cyl_axis(t_cyl *cyl)
{
	t_vec3	*ccyl;
	t_vec3	*rccyl;
	t_vec3	*ca;

	ccyl = new_vec3(0.0, 1.0, 0.0);
	rccyl = vec3_rotatexyz(ccyl, cyl->orientation);
	ca = vec3_normalize(rccyl);
	free(ccyl);
	free(rccyl);
	return (ca);
}

t_vec3	*get_cyl_up_p(t_cyl *cyl, t_vec3 *ca)
{
	t_vec3	*vtmp1;
	t_vec3	*vtmp2;
	t_vec3	*up_p;

	vtmp1 = new_vec3(cyl->size, cyl->size, cyl->size);
	vtmp2 = vec3_mul(vtmp1, ca);
	up_p = vec3_add(vtmp2, cyl->pos);
	free(vtmp1);
	free(vtmp2);
	return (up_p);
}

int		check_cyl_limits(t_cyl *cyl, t_vec3 *ca, double t, t_ray *ray)
{
	t_vec3	*hit_p;
	t_vec3	*tmp;
	t_vec3	*up_p;
	int		res;

	hit_p = new_vec3(ray->orig->x + ray->dir->x * t,
		ray->orig->y + ray->dir->y * t, ray->orig->z + ray->dir->z * t);
	tmp = vec3_sub(hit_p, cyl->pos);
	res = vec3_dot(ca, tmp) >= 0;
	free(tmp);
	if (res)
	{
		up_p = get_cyl_up_p(cyl, ca);
		tmp = vec3_sub(hit_p, up_p);
		res = vec3_dot(ca, tmp) <= 0;
		free(tmp);
		free(hit_p);
		free(up_p);
		return (res);
	}
	else
	{
		free(hit_p);
		return (0);
	}
}
