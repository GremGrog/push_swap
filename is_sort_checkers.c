/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:20:41 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 16:54:23 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_range_sort(t_stack *a, int bottom, int top)
{
	int	i;

	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->arr[i].index != a->min && a->arr[i].index != a->max)
		{
			if (a->arr[i].index > bottom && a->arr[i].index < top)
				return (-1);
		}
		i--;
	}
	return (0);
}

int		is_more_sort(t_stack *a, int med)
{
	int	i;

	i = a->used_size - 1;
	while (i >= 0)
	{
		if (a->arr[i].index != a->max && a->arr[i].index >= med)
			return (-1);
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
		if (a->arr[i].index != a->min && a->arr[i].index <= med)
			return (-1);
		i--;
	}
	return (0);
}

int		is_it_sort(t_stack *a)
{
	int	i;

	i = a->used_size - 1;
	while (i > 0)
	{
		if (a->arr[i].val > a->arr[i - 1].val)
			return (1);
		i--;
	}
	return (0);
}

int		is_it_dup(t_stack *a)
{
	int	i;
	int	j;
	int	f;

	i = a->used_size - 1;
	j = 0;
	f = 0;
	while (i < a->used_size)
	{
		j = 0;
		f = 0;
		while (j < a->used_size)
		{
			if (a->arr[i].val == a->arr[j].val)
				f++;
			j++;
		}
		if (f > 1)
			return (1);
		i++;
	}
	return (0);
}
