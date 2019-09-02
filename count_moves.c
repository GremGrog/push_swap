/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:19:08 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/02 19:25:30 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	unit_rotate(t_num *num)
{

	if (num->ra > num->rb && num->ra != 0 && num->rb != 0)
	{
		num->rr = num->rb;
		num->rb = 0;
	}
	if (num->ra < num->rb && num->ra != 0 && num->rb != 0)
	{
		num->rr = num->ra;
		num->ra = 0;
	}
	else if (num->ra ==  num->rb && num->ra != 0 &&  num->rb != 0)
	{
		num->rr = num->ra;
		num->ra = 0;
		num->rb = 0;
	}
	else
		num->rr = 0;
}

void	unit_rev_rotate(t_num *num)
{

	if (num->rra > num->rrb && num->rra != 0 && num->rrb != 0)
	{
		num->rrr = num->rrb;
		num->rrb = 0;
	}
	if (num->rra < num->rrb && num->rra != 0 && num->rrb != 0)
	{
		num->rrr = num->rra;
		num->rra = 0;
	}
	else if (num->rra ==  num->rrb && num->rra != 0 &&  num->rrb != 0)
	{
		num->rrr = num->rra;
		num->rra = 0;
		num->rrb = 0;
	}
	else
		num->rrr = 0;
}

t_num	unit_moves(t_num val)
{
	unit_rotate(&val);
	unit_rev_rotate(&val);
	val.total_moves = val.ra + val.rb + val.rra + val.rrb + val.rr + val.rrr + 1;
	return (val);
}

t_num	count_moves_for_num(t_stack *a, t_stack *b, t_num val, int i)
{
	int half;
	int	j;
	
	set_to_zero_moves(&val);
	j = 0;
	half = b->used_size / 2;
	if (i < half)
		val.rrb = 0 + i + 1;
	else if (i >= half)
		val.rb = b->used_size - i - 1;
	while (j < a->used_size)
	{
		if (a->arr[j].index < val.index && a->arr[j + 1].index > val.index)
			break ;
		j++;
	}
	half = a->used_size / 2;
	if (j < half)
		val.rra = j + 1;
	else if (j >= half)
		val.ra = j - 1 + 1;
	val = unit_moves(val);
	return (val);
}

void	count_moves(t_stack *a, t_stack *b)
{
	int	i;

	i = b->used_size - 1;
	while (i >= 0)
	{
		b->arr[i] = count_moves_for_num(a, b, b->arr[i], i);
		i--;
	}
}