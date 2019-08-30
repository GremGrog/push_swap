/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:20:03 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 16:12:45 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_num	find_min(t_stack *st)
// {
// 	int		i;
// 	t_num	min;

// 	i = st->used_size - 1;
// 	min.val = st->arr[i].val;
// 	min.index = st->arr[i].index;
// 	while (i >= 0)
// 	{
// 		if (min.val > st->arr[i].val)
// 		{
// 			min.val = st->arr[i].val;
// 			min.index = st->arr[i].index;
// 		}
// 		i--;
// 	}
// 	return (min);
// }


// t_num	find_max(t_stack *st)
// {
// 	int		i;
// 	t_num	max;

// 	i = st->used_size - 1;
// 	max.val = st->arr[i].val;
// 	max.index = st->arr[i].index;
// 	while (i >= 0)
// 	{
// 		if (max.val < st->arr[i].val)
// 		{
// 			max.val = st->arr[i].val;
// 			max.index = st->arr[i].index;
// 		}
// 		i--;
// 	}
// 	return (max);
// }

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

// void	get_min_max(t_stack *stck)
// {
// 	stck->min = find_min(stck);
// 	stck->max = find_max(stck);
// }