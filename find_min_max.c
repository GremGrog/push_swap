/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:20:03 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 16:52:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *st)
{
	int		i;
	int		min;

	i = st->used_size - 1;
	min = st->arr[i].index;
	while (i >= 0)
	{
		if (min > st->arr[i].index)
			min = st->arr[i].index;
		i--;
	}
	return (min);
}

int		find_max(t_stack *st)
{
	int		i;
	int		max;

	i = st->used_size - 1;
	max = st->arr[i].index;
	while (i >= 0)
	{
		if (max < st->arr[i].index)
			max = st->arr[i].index;
		i--;
	}
	return (max);
}

void	get_min_max(t_stack *stck)
{
	stck->min = find_min(stck);
	stck->max = find_max(stck);
}
