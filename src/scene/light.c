/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 21:47:14 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/16 16:52:49 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	*new_light(void)
{
	t_light *new_spot;
	if (!(new_spot = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	new_spot->next = NULL;
	return (new_spot);
}

void	push_back_light(t_light **first_light, t_light *new_light)
{
	t_light	*tmp;

	if (*first_light == NULL)
		*first_light = new_light;
	else
	{
		tmp = *first_light;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_light;
	}
}

int		len_lights(t_light *first_light)
{
	t_light	*tmp;
	int		i;

	tmp = first_light;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	free_lights(t_light *light)
{
	t_light	*current;
	t_light	*next;

	current = light;
	while (current)
	{
		next = current->next;
		free(current->pos);
		free(current->color);
		free(current);
		current = next;
	}
}