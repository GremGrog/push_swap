/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/28 20:01:24 by fmasha-h         ###   ########.fr       */
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

void    push_swap(int argc, char **argv)
{
    t_stack     *a;
	t_stack		*b;

    a = create_argv_stack(argc, argv);
	b = create_second_stack(a->size);
	print_stack(a, b);
	if (a->size == 3)
		sort_three(a);
	// push_b(a, b);
	// swap_a(a);
	// rotate_a(a);
	// swap_a(a);
	// rev_rotate_a(a);
	// rotate_a(a);
	// rev_rotate_a(a);
	// rev_rotate_a(a);
	print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
}