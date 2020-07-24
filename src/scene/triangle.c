/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:23:36 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:39:11 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tri	*new_tri(void)
{
	t_tri	*new_tri;

	if (!(new_tri = (t_tri *)malloc(sizeof(t_tri))))
		return (NULL);
	new_tri->next = NULL;
	return (new_tri);
}

void	push_back_tri(t_tri **first_tri, t_tri *new_tri)
{
	t_tri	*tmp;

	if (*first_tri == NULL)
		*first_tri = new_tri;
	else
	{
		tmp = *first_tri;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_tri;
	}
}
