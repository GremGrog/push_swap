/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_b_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:50:50 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 10:54:25 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_b(t_stack *b)
{
	if (b->used_size < 2)
		return ;
	swap_top(b);
	ft_printf("sb\n");
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->used_size == 0)
		return ;
	b->used_size++;
	b->arr[b->used_size - 1].index = a->arr[a->used_size - 1].index;
	b->arr[b->used_size - 1].val = a->arr[a->used_size - 1].val;
	a->arr[a->used_size - 1].index = -1;
	a->used_size--;
	ft_printf("pb\n");
}

void	rotate_b(t_stack *b)
{
	rotate_stck(b);
	ft_printf("rb\n");
}

void	rev_rotate_b(t_stack *b)
{
	rev_rotate_stck(b);
	ft_printf("rrb\n");
}
