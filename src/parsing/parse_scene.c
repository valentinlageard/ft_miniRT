/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:43 by vlageard          #+#    #+#             */
/*   Updated: 2020/08/05 20:39:35 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_correct_win_size(t_prog *prog)
{
	int		*screen_xsize;
	int		*screen_ysize;

	if (!(screen_xsize = (int *)malloc(1 * sizeof(int))))
		return ;
	if (!(screen_ysize = (int *)malloc(1 * sizeof(int))))
		return ;
	mlx_get_screen_size(prog->mlx_ptr, screen_xsize, screen_ysize);
	if (prog->win_width > (unsigned)(*screen_xsize))
		prog->win_width = (unsigned)(*screen_xsize);
	if (prog->win_height > (unsigned)(*screen_ysize))
		prog->win_height = (unsigned)(*screen_ysize);
	free(screen_xsize);
	free(screen_ysize);
}

void	parse_resolution(char *line, t_prog *prog)
{
	char	**words;

	if (prog->win_width != 0 || prog->win_height != 0)
		prog->errnum = -2;
	words = ft_split(line, "\t ");
	if (!(check_resolution(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		return ;
	}
	prog->win_width = ft_atoi(words[1]);
	prog->win_height = ft_atoi(words[2]);
	ft_free_words(words);
	check_correct_win_size(prog);
}

void	parse_camera(char *line, t_prog *prog)
{
	char	**words;
	t_cam	*new_cam;

	words = ft_split(line, "\t ");
	if (!(check_camera(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		return ;
	}
	else
	{
		if (!(new_cam = new_camera()))
			prog->errnum = errno;
		else
		{
			new_cam->pos = word_to_vector3(words[1]);
			new_cam->orientation = word_to_vector3(words[2]);
			new_cam->fov = ft_atoi(words[3]);
			push_back_cam_and_set_current(new_cam, prog);
		}
	}
	if (!(new_cam->pos) || !(new_cam->orientation))
		prog->errnum = errno;
	ft_free_words(words);
}

void	parse_ambient(char *line, t_prog *prog)
{
	char	**words;

	if (prog->ambient_color)
	{
		prog->errnum = -2;
		return ;
	}
	words = ft_split(line, "\t ");
	if (!(check_ambient(words)))
	{
		ft_printf("EH OAUIS !\n");
		ft_free_words(words);
		prog->errnum = -2;
		return ;
	}
	prog->ambient_intensity = ft_atof(words[1]);
	prog->ambient_color = word_to_color(words[2]);
	ft_free_words(words);
}

void	parse_light(char *line, t_prog *prog)
{
	char	**words;
	t_light	*new_spot;

	words = ft_split(line, "\t ");
	if (!(check_light(words)))
	{
		ft_free_words(words);
		prog->errnum = -2;
		return ;
	}
	else
	{
		if (!(new_spot = new_light()))
			prog->errnum = errno;
		else
		{
			new_spot->pos = word_to_vector3(words[1]);
			new_spot->intensity = ft_atof(words[2]);
			new_spot->color = word_to_color(words[3]);
			if (!(new_spot->pos) || !(new_spot->color))
				prog->errnum = errno;
			push_back_light(&(prog->lights), new_spot);
		}
	}
	ft_free_words(words);
}
