/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:06:31 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/05 16:16:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	*new_pl(void)
{
	t_plane	*new_plane;
	
	if (!(new_plane = (t_plane *)malloc(sizeof(t_plane))))
		return (NULL);
	new_plane->next = NULL;
	return(new_plane);
}

void	push_back_plane(t_plane **first_plane, t_plane *new_plane)
{
	t_plane	*tmp;

	if (*first_plane == NULL)
		*first_plane = new_plane;
	else
	{
		tmp = *first_plane;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_plane;
	}
}