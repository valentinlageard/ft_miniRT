/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:47:36 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/21 18:14:10 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_line(char *line, t_prog *prog) {
	if (line[0] == 'R')
		parse_resolution(line, prog);
	else if (line[0] == 'A')
		parse_ambient(line, prog);
	else if (line[0] == 'c')
		parse_camera(line, prog);
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
}

void	parse_file(char *filename, t_prog *prog)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	while ((ret = ft_get_next_line(fd, &line)) > 0)
	{
		parse_line(line, prog);
		free(line);
	}
	parse_line(line, prog);
	free(line);
}