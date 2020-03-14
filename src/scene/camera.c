/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/14 17:59:52 by vlageard         ###   ########.fr       */
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

void	compute_camera_projection(t_prog *prog)
{
	double	inv_ratio;

	printf("fov : %i\n", prog->current_cam->fov);
	prog->half_width = (double)(tan((prog->current_cam->fov * (PI/180))/2.0));
	printf("half_width : %f\n", prog->half_width);
	inv_ratio = ((double)(prog->win_height))/((double)(prog->win_width));
	prog->half_height = inv_ratio * prog->half_width;
	printf("half_height : %f\n", prog->half_height);
}