/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:43 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/11 15:28:27 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_resolution(char *line, t_prog *prog)
{
	char	**words;
	
	words = ft_split(line, "\t ");
	prog->win_width = ft_atoi(words[1]);
	prog->win_height = ft_atoi(words[2]);
	free(words);
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
	free(words);
}

void parse_ambient(char *line, t_prog *prog)
{
	char	**words;

	words = ft_split(line, "\t ");
	prog->ambient_intensity = ft_atof(words[1]);
	prog->ambient_color = word_to_color(words[2]);
	free(words);
}

void	parse_light(char *line, t_prog *prog)
{
	char	**words;
	t_light	*new_spot;

	words = ft_split(line, "\t ");
	new_spot = new_light();
	new_spot->pos = word_to_vector3(words[1]);
	new_spot->intensity = ft_atof(words[2]);
	new_spot->color = word_to_color(words[3]);
	push_back_light(&(prog->lights), new_spot);
	free(words);
}