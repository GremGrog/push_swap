/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/30 20:29:05 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_stack *a)
{
	if ((a->min.index == 0 && a->max.index == 2) || 
	(a->min.index == 2 && a->max.index == 1) || (a->min.index == 1 && a->max.index == 0))
		swap_a(a);
	if (a->min.index == 1 && a->max.index == 2)
		rotate_a(a);
	if (a->min.index == 0 && a->max.index == 1)
		rev_rotate_a(a);
}

int		is_more_sort(t_stack *a, int med)
{
	int	i;

	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->arr[i].index > med)
			return(-1);
		i--;
	}
	return (0);
}

int		is_less_sort(t_stack *a, int med)
{
	int	i;

	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->arr[i].index < med)
			return(-1);
		i--;
	}
	return (0);
}

int		find_aver_val(t_stack *a)
{
	int	i;
	int	mean;

	i = 0;
	mean = 0;
	while (i < a->used_size)
	{
		mean += a->arr[i].index;
		i++;
	}
	mean /= a->used_size;
	return (mean);
}


int		search_val(t_stack *stck, int val)
{
	int	i;
	int	j;
	int	search;

	i = stck->used_size - 1;
	j = 0;
	search = val;
	while (j < i)
	{
		if (stck->arr[i].index == search)
			return (1);
		if (stck->arr[j].index == search)
			return (0);
		j++;
		i--;
	}
	return (1);
}

int		search_less_values(t_stack *stck, int val)
{
	int	top;
	int	i;

	top = stck->used_size - 1;
	i = top;
	while (i > top / 2)
	{
		if (stck->arr[i].index < val)
			return (1);
		i--;
	}
	return (0);
}

void	kick_to_b_except_min_max(t_stack *a, t_stack *b)
{
	int	aver_val;
	int	min;
	int	max;
	int	i;

	i = a->used_size - 1;
	aver_val = find_aver_val(a);
	min = find_min(a);
	max = find_max(a);
	while (a->used_size > 3)
	{
		i = a->used_size - 1;
		if (a->arr[i].index != min && a->arr[i].index != max 
		&& a->arr[i].index != aver_val)
		{
			push_b(a, b);
		}
		else
			rotate_a(a);
	}
} 


void	sort_stacks(t_stack *a, t_stack *b)
{
	print_stack(a, b);
	kick_to_b_except_min_max(a, b);
	print_stack(a, b);
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
	// int			c;

    a = create_argv_stack(argc, argv);
	b = create_second_stack(a);
	// print_stack(a, b);
	quick_sort(b->arr, 0, b->used_size - 1);
	// print_stack(a, b);
	change_index(a, b);
	print_stack(a, b);
	set_to_zero_stack(b);
	// print_stack(a, b);
	sort_stacks(a, b);
}