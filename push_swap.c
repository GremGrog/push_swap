/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/02 19:54:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	kick_less_values(t_stack *a, t_stack *b, int value)
{
	int	i;
	
	i = a->used_size - 1;
	while (is_less_sort(a, value) == -1)
	{
		i = a->used_size - 1;
		if (a->arr[i].index != a->min && a->arr[i].index != a->max && a->arr[i].index <= value)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_more_values(t_stack *a, t_stack *b, int value)
{
	int	i;
	
	i = a->used_size - 1;
	while (is_more_sort(a, value) == -1)
	{
		i = a->used_size - 1;
		if (a->arr[i].index != a->min && a->arr[i].index != a->max && a->arr[i].index >= value)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_values_in_range(t_stack *a, t_stack *b, int bottom, int top)
{
	int	i;
	
	i = a->used_size - 1;
	while (is_range_sort(a, bottom, top) == -1)
	{
		i = a->used_size - 1;
		if (a->arr[i].index != a->min && a->arr[i].index != a->max && a->arr[i].index > bottom && a->arr[i].index <= top)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_to_b_except_min_max(t_stack *a, t_stack *b, int hold_min, int hold_max)
{
	int	i;
	int	aver_val;

	aver_val = find_aver_val(a);
	i = a->used_size - 1;
	kick_more_values(a, b, hold_max);
	kick_values_in_range(a, b, hold_min, hold_max);
	kick_less_values(a, b, hold_min);
}

void	kick_val_to_top(t_stack *a, int val)
{
	if (val <= a->used_size)
	{
		while (a->arr[a->used_size - 1].index != val)
			rev_rotate_a(a);
	}
	else
	{
		while (a->arr[a->used_size - 1].index != val)
			rotate_a(a);
	}
}
/*
** 1 - rotate_a;
** 2 - rotate_b
** 3 - rev_rotate_a
** 4 - rev_rotate_b
** 5 - rotate_rr
** 6 - rev_rotate_r
** 7 - push_a
*/
int		find_function(t_num *val, t_stack *a, t_stack *b)
{
	if (val->ra > 0)
		return (1);
	if (val->rb > 0)
		return (2);
	if (val->rra > 0)
		return (3);
	if (val->rrb > 0)
		return (4);
	if (val->rr > 0)
		return (5);
	if (val->rrr > 0)
		return (6);
	else
		return (7);
}

int	find_min_actions(t_stack *b)
{
	int	j;
	int	min;

	j = 0;
	min = b->arr[j].total_moves;
	while (j < b->used_size - 1)
	{
		if (b->arr[j].total_moves > b->arr[j + 1].total_moves)
			min = j;
		j++;
	}
	return (min);
}

void	do_moves(t_stack *a, t_stack *b)
{
	int	min_moves;

	min_moves = find_min_actions(b);
	if (find_function(b->arr[min_moves].index, a, b) == 1)
	{
		while (b->arr[min_moves].ra > 0)
		{
			rotate_a(a);
			b->arr[min_moves].ra--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 2)
	{
		while (b->arr[min_moves].rb > 0)
		{
			rotate_b(b);
			b->arr[min_moves].rb--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 3)
	{
		while (b->arr[min_moves].rra > 0)
		{
			rev_rotate_a(a);
			b->arr[min_moves].rra--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 4)
	{
		while (b->arr[min_moves].rrb > 0)
		{
			rev_rotate_b(b);
			b->arr[min_moves].rrb--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 5)
	{
		while (b->arr[min_moves].rr > 0)
		{
			rotate_rr(a, b);
			b->arr[min_moves].rr--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 6)
	{
		while (b->arr[min_moves].rrr > 0)
		{
			rev_rotate_r(a, b);
			b->arr[min_moves].rrr--;
		}
	}
	if (find_function(b->arr[min_moves].index, a, b) == 1)
		push_a(a, b);
}


void	sort_stacks(t_stack *a, t_stack *b, int hold_min, int hold_max)
{
	print_stack(a, b);
	kick_to_b_except_min_max(a, b, hold_min, hold_max);
	count_moves(a, b);
	print_stack(a, b);
	do_moves(a, b);
}

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

void    push_swap(int argc, char **argv)
{
    t_stack     *a;
	t_stack		*b;
	int	hold_min;
	int	hold_max;

    a = create_argv_stack(argc, argv);
	b = create_second_stack(a);
	quick_sort(b->arr, 0, b->used_size - 1);
	// print_stack(a, b);
	change_index(a, b);
	hold_min = b->arr[a->used_size / 3].index;
	hold_max = b->arr[a->used_size - a->used_size / 3].index;
	set_to_zero_stack(b);
	// print_stack(a, b);
	sort_stacks(a, b, hold_min, hold_max);
}