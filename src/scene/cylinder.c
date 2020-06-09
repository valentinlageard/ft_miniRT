/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:33:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/09 21:54:37 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cyl	*new_cyl(void)
{
	t_cyl	*new_cyl;
	
	if (!(new_cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (NULL);
	new_cyl->next = NULL;
	return(new_cyl);
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
	rccyl = vec3_rotateXYZ(ccyl, cyl->orientation);
	ca = vec3_normalize(rccyl);
	free(ccyl);
	free(rccyl);
	return (ca);
}