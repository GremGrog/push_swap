/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:13:33 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 17:36:17 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_function(t_num val)
{
	if (val.ra > 0)
		return (1);
	if (val.rb > 0)
		return (2);
	if (val.rra > 0)
		return (3);
	if (val.rrb > 0)
		return (4);
	if (val.rr > 0)
		return (5);
	if (val.rrr > 0)
		return (6);
	else
		return (7);
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

int		do_move(t_stack *stck, int counter, void (*f)(t_stack *))
{
	while (counter > 0)
	{
		(*f)(stck);
		counter--;
	}
	return (0);
}

int		do_m_b(t_stack *a, t_stack *b, int c, void (*f)(t_stack *, t_stack *))
{
	while (c > 0)
	{
		(*f)(a, b);
		c--;
	}
	return (0);
}

void	do_moves(t_stack *a, t_stack *b)
{
	int	min_moves;

	min_moves = find_min_actions(b);
	if (find_function(b->arr[min_moves]) == 1)
		b->arr[min_moves].ra = do_move(a, b->arr[min_moves].ra, rotate_a);
	if (find_function(b->arr[min_moves]) == 2)
		b->arr[min_moves].rb = do_move(b, b->arr[min_moves].rb, rotate_b);
	if (find_function(b->arr[min_moves]) == 3)
		b->arr[min_moves].rra = do_move(a, b->arr[min_moves].rra, rev_rotate_a);
	if (find_function(b->arr[min_moves]) == 4)
		b->arr[min_moves].rrb = do_move(b, b->arr[min_moves].rrb, rev_rotate_b);
	if (find_function(b->arr[min_moves]) == 5)
		b->arr[min_moves].rr = do_m_b(a, b, b->arr[min_moves].rr, rotate_rr);
	if (find_function(b->arr[min_moves]) == 6)
		b->arr[min_moves].rrr = \
		do_m_b(a, b, b->arr[min_moves].rrr, rev_rotate_r);
	if (find_function(b->arr[min_moves]) == 7)
		push_a(a, b);
}
