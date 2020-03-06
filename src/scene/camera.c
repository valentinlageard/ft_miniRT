/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 17:48:16 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cam	*new_camera(void) {
	t_cam	*new_cam;
	
	if (!(new_cam = (t_cam *)malloc(sizeof(t_cam))))
		return (NULL);
	new_cam->next = NULL;
	return (new_cam);
}

void	push_back_cam(t_cam **first_cam, t_cam *new_cam)
{
	t_cam	*tmp;

	if (*first_cam == NULL)
		*first_cam = new_cam;
	else
	{
		tmp = *first_cam;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cam;		
	}
}