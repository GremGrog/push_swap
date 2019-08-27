/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:50:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/27 19:54:39 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_stack *a, t_stack *b)
{
	if (a->used_size < 2 || b->used_size < 2)
		return ;
	swap(&(a->arr[a->used_size - 1].val), &(a->arr[a->used_size - 2].val));
	swap(&(b->arr[b->used_size - 1].val), &(b->arr[b->used_size - 2]).val);
	ft_printf("ss\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	t_num	tmp;
	int		i;

	i = b->used_size - 1;
	tmp = b->arr[i];
	while (i > 0)
	{
		b->arr[i].val = b->arr[i - 1].val;
		b->arr[i].index = b->arr[i - 1].index + 1;
		i--;
	}
	b->arr[i].val = tmp.val;
	b->arr[i].index = 0;
	i = a->used_size - 1;
	tmp = a->arr[i];
	while (i > 0)
	{
		a->arr[i].val = a->arr[i - 1].val;
		a->arr[i].index = a->arr[i - 1].index + 1;
		i--;
	}
	a->arr[i].val = tmp.val;
	a->arr[i].index = 0;
	ft_printf("rr\n");
}