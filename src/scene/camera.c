/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 17:51:35 by vlageard         ###   ########.fr       */
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
	double	theta;
	double	half_width;
	double	half_height;
	double	ratio;

	theta = (double)(prog->current_cam->fov)*PI/180.0;
	half_width = (double)(tan(theta/2));
	ratio = ((double)(prog->win_width))/((double)(prog->win_height));
	half_height = ratio * half_width;
	prog->lower_left_corner = new_vec3(-half_width, -half_height, -1.0);
	prog->horizontal = new_vec3(2 * half_width, 0.0, 0.0);
	prog->vertical = new_vec3(0.0, 2 * half_height, 0.0);
}