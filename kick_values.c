/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:04:04 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 17:12:07 by fmasha-h         ###   ########.fr       */
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
		if (a->arr[i].index != a->min && a->arr[i].index != a->max &&
		a->arr[i].index <= value)
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
		if (a->arr[i].index != a->min && a->arr[i].index != a->max &&
		a->arr[i].index >= value)
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
		if (a->arr[i].index != a->min && a->arr[i].index != a->max &&
		a->arr[i].index > bottom && a->arr[i].index < top)
			push_b(a, b);
		else
			rotate_a(a);
	}
}

void	kick_to_b_except_min_max(t_stack *a, t_stack *b, int h_min, int h_max)
{
	int	i;
	int	aver_val;

	aver_val = find_aver_val(a);
	i = a->used_size - 1;
	kick_more_values(a, b, h_max);
	kick_values_in_range(a, b, h_min, h_max);
	kick_less_values(a, b, h_min);
}

void	kick_val_to_top(t_stack *a, int val)
{
	if (val <= a->used_size / 2)
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
