/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:05:59 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/25 16:17:14 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	fill_bmp_header(char **bmp, t_prog *prog)
{
	unsigned int	img_size;

	img_size = prog->win_width * prog->win_height * 3;
	*(unsigned short *)*bmp = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*bmp + 2) = (img_size + HEADER_SIZE);
	*(unsigned int *)(*bmp + 6) = (unsigned int)0;
	*(unsigned char *)(*bmp + 10) = HEADER_SIZE;
	*(unsigned int *)(*bmp + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*bmp + 18) = prog->win_width;
	*(unsigned int *)(*bmp + 22) = prog->win_height;
	*(unsigned short *)(*bmp + 26) = 1;
	*(unsigned short *)(*bmp + 28) = 24;
	*(unsigned int *)(*bmp + 30) = 0;
	*(unsigned int *)(*bmp + 34) = (unsigned int)img_size; // Maybe 0 since no compression
	*(unsigned int *)(*bmp + 38) = 3780; // May be 0
	*(unsigned int *)(*bmp + 42) = 3780; // May be 0
	*(unsigned int *)(*bmp + 46) = 0;
	*(unsigned int *)(*bmp + 50) = 0;
}

void	fill_bmp_data(char **bmp, t_prog *prog)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = HEADER_SIZE;
	y = prog->win_height - 1;
	while (y)
	{
		x = 0;		
		while (x < prog->win_width)
		{
			*(*bmp + i++) = *(prog->img_pixels + ((y * prog->win_width) + x) * 4 + 2);
			*(*bmp + i++) = *(prog->img_pixels + ((y * prog->win_width) + x) * 4 + 1);
			*(*bmp + i++) = *(prog->img_pixels + ((y * prog->win_width) + x) * 4 + 0);
			x++;
		}
		y--;
	}
}

char	*get_filename(t_prog *prog)
{
	unsigned int	name_len;
	char			*filename;

	name_len = ft_strlen(prog->name);
	if (!(filename = (char *)malloc(sizeof(char *) * (name_len + 4 + 1))))
		return (NULL);
	ft_strlcpy(filename, prog->name, name_len + 1);
	ft_strlcat(filename, ".bmp", name_len + 4 + 1);
	return (filename);
}

void	export_bmp(t_prog *prog)
{
	char			*bmp;
	unsigned int	img_size;
	char			*filename;
	int				fd;

	filename = get_filename(prog);
	printf("%s\n", filename);
	img_size = (unsigned int)prog->win_width * (unsigned int)prog->win_height * 3;
	if (!(bmp = malloc((img_size + HEADER_SIZE) * sizeof(char))))
		quit(prog);
	fill_bmp_header(&bmp, prog);
	fill_bmp_data(&bmp, prog);
	if ((fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		quit(prog);
	write(fd, bmp, (img_size + HEADER_SIZE));
	close(fd);
	free(filename);
}