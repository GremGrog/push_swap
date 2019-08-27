/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_a_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 15:15:41 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/27 20:08:31 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	if (a->used_size < 2)
		return ;
	swap(&(a->arr[a->used_size - 1].val), &(a->arr[a->used_size - 2].val));
	ft_printf("sa\n");
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->used_size == 0)
		return ;
	a->used_size++;
	a->arr[a->used_size - 1] = b->arr[b->used_size - 1];
	b->arr[b->used_size - 1].index = -1;
	b->used_size--;
	ft_printf("pa\n");
}

void	rotate_a(t_stack *a)
{
	t_num	tmp;
	int		i;

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
	ft_printf("ra\n");
}

void	rev_rotate_a(t_stack *a)
{
	t_num	tmp;
	int		i;

	i = 0;
	tmp = a->arr[i];
	while (i < a->used_size - 1)
	{
		a->arr[i].val = a->arr[i + 1].val;
		a->arr[i].index = a->arr[i + 1].index -1;
		i++;
	}
	a->arr[i].val = tmp.val;
	a->arr[i].index = a->used_size - 1;
	ft_printf("ra\n");
}