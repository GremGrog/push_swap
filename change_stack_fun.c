/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stack_fun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 19:45:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 16:51:44 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack *stck)
{
	if (stck->used_size < 2)
		return ;
	swap(&(stck->arr[stck->used_size - 1].val), \
	&(stck->arr[stck->used_size - 2].val));
}

void	rotate_stck(t_stack *stck)
{
	t_num	tmp;
	int		i;

	i = stck->used_size - 1;
	tmp = stck->arr[i];
	while (i > 0)
	{
		stck->arr[i].index = stck->arr[i - 1].index;
		stck->arr[i].val = stck->arr[i - 1].val;
		i--;
	}
	stck->arr[i].val = tmp.val;
	stck->arr[i].index = tmp.index;
}

void	rev_rotate_stck(t_stack *stck)
{
	t_num	tmp;
	int		i;

	i = 0;
	tmp.index = stck->arr[i].index;
	tmp.val = stck->arr[i].val;
	while (i < stck->used_size - 1)
	{
		stck->arr[i].index = stck->arr[i + 1].index;
		stck->arr[i].val = stck->arr[i + 1].val;
		i++;
	}
	stck->arr[i].val = tmp.val;
	stck->arr[i].index = tmp.index;
}
