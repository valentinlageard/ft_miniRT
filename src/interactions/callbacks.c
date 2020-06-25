/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:47:53 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/23 16:16:15 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_callback(int k, int *param)
{
	printf("k : %d\n", k);
	if (k == 99)
		change_camera((t_prog *)(param));
	if (k == 65307)
		quit((t_prog *)(param));
	return (0);
}

/*int	mouse_callback(int button, int x, int y , int *param)
{
	t_prog	*prog;
	printf("button : %d\n", button);
	printf("x : %d\n", x);
	printf("y : %d\n", y);
	prog = (t_prog *)param;
	prog = prog;
	return (0);
}*/

int	exit_callback(int *param)
{
	quit((t_prog *)param);
	return (0);
}