/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:29:30 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/29 17:02:23 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_commands(t_stack *stck, t_num elem)
{
	t_num	mid;
	int		com;

	mid.index = stck->used_size / 2;
	com = 0;
	if (elem.index >= mid.index)
	{
		if (elem.index + 1 < stck->used_size - 1)
		{
			rotate_stck(stck);
			com++;
			// com = count_commands(stck, elem);
		}
		if (elem.index + 1 == stck->used_size - 1)
		{
			swap_top(stck);
			com++;
			// com = count_commands(stck, elem);
		}
		if (elem.index == stck->used_size - 1)
		{
			return (com);
		}
	}
	return (com);
}