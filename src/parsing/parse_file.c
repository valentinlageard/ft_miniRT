/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:36 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/29 20:28:28 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_necessities(t_prog *prog)
{
	if (!prog->win_width || !prog->win_height)
		return (0);
	if (!prog->ambient_color)
		return (0);
	if (!prog->cams || !prog->current_cam)
		return (0);
	return (1);
}

void	parse_name(char *fn, t_prog *prog)
{
	
	unsigned int	fn_len;

	fn_len = ft_strlen(fn);
	if (!(prog->name = (char *)malloc(sizeof(char) * fn_len - 3 + 1)))
		error_quit(prog, errno);
	ft_strlcpy(prog->name, fn, fn_len - 2);
}

void	parse_line(char *line, t_prog *prog)
{
	if (line[0] == 'R')
		parse_resolution(line, prog);
	else if (line[0] == 'A')
		parse_ambient(line, prog);
	else if (line[0] == 'c')
	{
		if (line[1] == 'y')
			parse_cyl(line, prog);
		else
			parse_camera(line, prog);
	}
	else if (line[0] == 'l')
		parse_light(line, prog);
	else if (line[0] == 's')
	{
		if (line[1] == 'p')
			parse_sphere(line, prog);
		if (line[1] == 'q')
			parse_square(line, prog);
	}
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, prog);
	else if (line[0] == 't' && line[1] == 'r')
		parse_triangle(line, prog);
	else if (line[0])
		prog->errnum = -2;
}

void	parse_file(char *filename, t_prog *prog)
{
	int		fd;
	int		ret;
	char	*line;

	check_filename(filename, prog);
	fd = open(filename, O_RDONLY);
	// NEED SECURITY HERE
	while ((ret = ft_get_next_line(fd, &line)) > 0)
	{
		printf("line : %s\n", line);
		parse_line(line, prog);
		free(line);
		printf("prog->errnum : %i\n", prog->errnum);
		if (prog->errnum != 0)
			break;
	}
	if (prog->errnum == 0)
	{
		printf("line : %s\n", line);
		parse_line(line, prog);
		free(line);
	}
	printf("prog->errnum : %i\n", prog->errnum);
	close(fd);
	if (!check_necessities(prog))
		prog->errnum = -2;
	if (prog->errnum != 0)
		error_quit(prog, prog->errnum);
}