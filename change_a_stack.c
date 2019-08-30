/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:15:41 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 15:39:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	if (a->used_size < 2)
		return ;
	swap_top(a);
	ft_printf("sa\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->used_size == 0)
		return ;
	a->used_size++;
	a->arr[a->used_size - 1].index = b->arr[b->used_size - 1].index;
	a->arr[a->used_size - 1].val = b->arr[b->used_size - 1].val;
	b->arr[b->used_size - 1].index = -1;
	b->used_size--;
	// get_min_max(a);
	// get_min_max(b);
	ft_printf("pa\n");
}

void	rotate_a(t_stack *a)
{
	rotate_stck(a);
	ft_printf("ra\n");
}

void	rev_rotate_a(t_stack *a)
{
	rev_rotate_stck(a);
	ft_printf("rra\n");
}
