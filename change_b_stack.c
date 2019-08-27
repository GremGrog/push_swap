/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:50:50 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/27 19:57:02 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *b)
{
	if (b->used_size < 2)
		return ;
	swap(&(b->arr[b->used_size - 1].val), &(b->arr[b->used_size - 2]).val);
	ft_printf("sb\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->used_size == 0)
		return ;
	b->used_size++;
	b->arr[b->used_size - 1] = a->arr[a->used_size - 1];
	b->arr[b->used_size - 1].index = b->used_size - 1;
	a->arr[a->used_size - 1].index = -1;
	a->used_size--;
	ft_printf("pb\n");
}

void	rotate_b(t_stack *b)
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
	ft_printf("rb\n");
}