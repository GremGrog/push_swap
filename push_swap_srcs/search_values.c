/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:22:29 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 10:55:18 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int		search_less_val(t_stack *stck, int val)
{
	int	i;
	int	j;

	i = stck->used_size - 1;
	j = 0;
	while (j < i)
	{
		if (stck->arr[i].index < val)
			return (1);
		if (stck->arr[j].index < val)
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
