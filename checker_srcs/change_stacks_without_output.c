/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_stacks_without_output.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:57:48 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/06 15:24:13 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_ss_stcks(t_stack *a, t_stack *b)
{
	if (a->used_size < 2 || b->used_size < 2)
		return ;
	swap_top(a);
	swap_top(b);
}

void	rotate_rr_stcks(t_stack *a, t_stack *b)
{
	rotate_stck(a);
	rotate_stck(b);
}

void	rev_rotate_stcks(t_stack *a, t_stack *b)
{
	rev_rotate_stck(a);
	rev_rotate_stck(b);
}
