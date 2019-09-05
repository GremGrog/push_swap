/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_both_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:50:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 10:54:33 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	change_index(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->used_size - 1;
	j = b->used_size - 1;
	while (i >= 0)
	{
		j = b->used_size - 1;
		while (j >= 0)
		{
			if (a->arr[i].val == b->arr[j].val)
				a->arr[i].index = b->arr[j].index;
			j--;
		}
		i--;
	}
}

void	swap_ss(t_stack *a, t_stack *b)
{
	if (a->used_size < 2 || b->used_size < 2)
		return ;
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_stck(a);
	rotate_stck(b);
	ft_printf("rr\n");
}

void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_stck(a);
	rev_rotate_stck(b);
	ft_printf("rrr\n");
}
