/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 17:44:56 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort_three(t_stack *a)
// {
// 	if ((a->min.index == 0 && a->max.index == 2) || 
// 	(a->min.index == 2 && a->max.index == 1) || (a->min.index == 1 && a->max.index == 0))
// 		swap_a(a);
// 	if (a->min.index == 1 && a->max.index == 2)
// 		rotate_a(a);
// 	if (a->min.index == 0 && a->max.index == 1)
// 		rev_rotate_a(a);
// }

int		find_min_actions(t_stack *b)
{
	int	j;
	int	min;

	j = b->used_size - 1;
	min = j;
	while (j >= 0)
	{
		if (b->arr[min].total_moves > b->arr[j].total_moves)
			min = j;
		j--;
	}
	return (min);
}

void	sort_stacks(t_stack *a, t_stack *b, int hold_min, int hold_max)
{
	kick_to_b_except_min_max(a, b, hold_min, hold_max);
	count_moves(a, b);
	while (b->used_size > 0)
	{
		count_moves(a, b);
		do_moves(a, b);
	}
	kick_val_to_top(a, a->max);	
}

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		hold_min;
	int		hold_max;

	a = create_argv_stack(argc, argv);
	if (is_it_sort(a) == 0 || (is_it_dup(a) == 1))
	{
		del_stack(a);
		return ;
	}
	b = create_second_stack(a);
	quick_sort(b->arr, 0, b->used_size - 1);
	change_index(a, b);
	hold_min = b->arr[a->used_size / 3].index;
	hold_max = b->arr[a->used_size - a->used_size / 3].index;
	set_to_zero_stack(b);
	sort_stacks(a, b, hold_min, hold_max);
	del_stack(a);
	del_stack(b);
}
