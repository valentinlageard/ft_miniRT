/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:43 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 17:31:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_resolution(char *line, t_prog *prog)
{
	char	**words;
	
	words = ft_split(line, "\t ");
	prog->win_width = ft_atoi(words[1]);
	prog->win_height = ft_atoi(words[2]);
}

void	parse_camera(char *line, t_prog *prog)
{
	char	**words;
	t_cam	*new_cam;

	words = ft_split(line, "\t ");
	new_cam = new_camera();
	new_cam->pos = word_to_vector3(words[1]);
	new_cam->orientation = word_to_vector3(words[2]);
	new_cam->fov = ft_atoi(words[3]);
	if (!prog->current_cam)
		prog->current_cam = new_cam;
	push_back_cam(&(prog->cams), new_cam);
}
