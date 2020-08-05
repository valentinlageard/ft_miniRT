/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/08/05 20:37:46 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam	*new_camera(void)
{
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

void	push_back_cam_and_set_current(t_cam *new_cam, t_prog *prog)
{
	if (!prog->current_cam)
		prog->current_cam = new_cam;
	push_back_cam(&(prog->cams), new_cam);
}

void	compute_camera_projection(t_prog *prog)
{
	double	inv_ratio;

	prog->half_width = (double)(tan((prog->current_cam->fov *
		(PI / 180)) / 2.0));
	inv_ratio = ((double)(prog->win_height)) / ((double)(prog->win_width));
	prog->half_height = inv_ratio * prog->half_width;
}

void	free_cams(t_cam *cam)
{
	t_cam	*current;
	t_cam	*next;

	current = cam;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->orientation);
		free(current);
		current = next;
	}
}
