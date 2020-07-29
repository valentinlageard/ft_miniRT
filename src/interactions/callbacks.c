/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:47:53 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/29 15:27:53 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_callback(int k, int *param)
{
	if (k == 99)
		change_camera((t_prog *)(param));
	if (k == 65307)
		quit((t_prog *)(param));
	return (0);
}

int	exit_callback(int *param)
{
	quit((t_prog *)param);
	return (0);
}
