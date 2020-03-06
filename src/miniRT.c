/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:02 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 19:01:03 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int ac, char **av)
{
	t_prog	*prog;

	if (ac >= 2)
	{
		prog = init_prog();
		// Check .rt
		parse_file(av[1], prog);
		//printf("prog->spheres->next->pos->x : %f\n", prog->spheres->next->pos->x);
		//printf("prog->spheres->next->next : %p\n", prog->spheres->next->next);
		// Compute raytraced image
		// Create window and print image
		// Wait for instructions
		init_win(prog->win_width, prog->win_height, prog);
	}
	if (*av != 0)
		return (0);
	return (0);
}