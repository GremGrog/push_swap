/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/29 21:59:36 by fmasha-h         ###   ########.fr       */
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

/**
 **	kick all numbers which more than average value to stack b form stack a
 **/

void	kick_more_aver_to_b(t_stack *a, t_stack *b, int aver_val)
{
	int	i;
	int	top_a;

	i = a->used_size - 1;
	while (is_more_sort(a, aver_val) == -1)
	{
		while (is_more_sort(a, aver_val) == -1 && i >= 0)
		{
			top_a = a->used_size - 1;
			if (a->arr[top_a].index > aver_val)
				push_b(a, b);
			else if (a->arr[top_a].index <= aver_val)
				rotate_a(a);
			// print_stack(a, b);
			i--;
		}
		i = top_a;
	}
}

/**
 **	kick all numbers which more than average value to stack a form stack b
 **/

void	kick_more_to_a(t_stack *a, t_stack *b)
{
	int	top_a;
	int	top_b;

	top_a = a->used_size - 1;
	top_b = b->used_size - 1;
	while (b->used_size > 0)
	{
		top_a = a->used_size - 1;
		top_b = b->used_size - 1;
		if (a->arr[top_a].index + 1 ==  b->arr[top_b].index)
		{
			// rotate_a(a);
			push_a(a, b);
			// print_stack(a, b);
		}
		else
			rotate_b(b);
		// print_stack(a, b);
	}
	// rotate_a(a);
}

/**
 **	kick all numbers which less than number of top in stack a from stack b to stack a
 **/

void	kick_less_from_b(t_stack *a, t_stack *b)
{
	int	top_a;
	int	top_b;

	top_a = a->used_size - 1;
	top_b = b->used_size - 1;
	while (b->used_size > 0)
	{
		top_a = a->used_size - 1;
		top_b = b->used_size - 1;
		if (a->arr[top_a].index - 1 == b->arr[top_b].index)
			push_a(a, b);
		else
			rotate_b(b);
	}	
}

/**
 **	kick average value at the top of stack a
 **/

void	kick_average_on_top(t_stack *a, int aver_val)
{
	int	i;

	i = a->used_size;
	while (a->arr[i].index != aver_val)
		i--;
	if (i <= a->used_size / 2)
	{
		i = a->used_size - 1;
		while (a->arr[i].index != aver_val)
		{
			i = a->used_size - 1;
			rev_rotate_a(a);
		}
	}
	else
	{
		i = a->used_size - 1;
		while (a->arr[i].index != aver_val)
		{
			i = a->used_size - 1;
			rotate_a(a);
		}
	}
}

void	kick_less_to_b(t_stack *a, t_stack *b, int aver_val)
{
	int	i;
	int	top_a;

	i = a->used_size - 1;
	top_a = a->used_size - 1;
	while (is_less_sort(a, aver_val) == -1)
	{
		while (is_less_sort(a, aver_val) == -1 && i >= 0)
		{
			top_a = a->used_size - 1;
			if (a->arr[top_a].index >= aver_val)
				rotate_a(a);
			else if (a->arr[top_a].index < aver_val)
				push_b(a, b);
			i--;
			// print_stack(a, b);
		}	
	}
}

void	q_sort_stacks(t_stack *a, t_stack *b)
{
	int	aver_val;

	aver_val = find_aver_val(a);
	kick_more_aver_to_b(a, b, aver_val);
	kick_average_on_top(a, aver_val);
	print_stack(a, b);
	kick_more_to_a(a, b);
	print_stack(a, b);
	kick_less_to_b(a, b, aver_val);
	print_stack(a, b);
	// kick_less_from_b(a, b);
	// print_stack(a, b);


	// kick_less_to_b(a, b, aver_val);
	// kick_average_on_top(a, aver_val);
	// print_stack(a, b);
	// kick_less_from_b(a, b);
	// print_stack(a, b);
	// kick_more_aver_to_b(a, b, aver_val);
	// print_stack(a, b);
	// kick_less_to_b(a, b, aver_val);
	// print_stack(a, b);
	// kick_average_on_top(a, aver_val);
	// print_stack(a, b);
	// kick_more_aver_to_b(a, b, aver_val);
	// print_stack(a, b);

	// kick_more_to_a(a, b);
	// print_stack(a, b);
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
	print_stack(a, b);
	quick_sort(b->arr, 0, b->used_size - 1);
	// print_stack(a, b);
	change_index(a, b);
	// print_stack(a, b);
	set_to_zero_stack(b);
	// print_stack(a, b);
	q_sort_stacks(a, b);
	// // c = count_commands(a, a->arr[4]);
	// // ft_printf("%d\n", c);
	// // if (a->size == 3)
	// 	// sort_three(a);

	// 	if (a->used_size == 3)
	// 	sort_three(a);
	// print_stack(a, b);
	// sort_three(a);
	// push_b(a, b);
	// print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
	// swap_a(a);
	// rotate_a(a);
	// swap_a(a);
	// rev_rotate_a(a);
	// rev_rotate_a(a);
	// rev_rotate_a(a);
	// print_stack(a, b);
	// push_a(a, b);
	// print_stack(a, b);
	// push_a(a, b);
	// print_stack(a, b);
}