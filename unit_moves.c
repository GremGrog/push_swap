/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:56:52 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 17:02:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	unit_rotate(t_num num)
{
	if (num.ra > 0 && num.rb > 0 && num.ra > num.rb)
	{
		num.rr = num.rb;
		num.ra = num.ra - num.rb;
		num.rb = 0;
	}
	else if (num.ra > 0 && num.rb > 0 && num.ra < num.rb)
	{
		num.rr = num.ra;
		num.rb = num.rb - num.ra;
		num.ra = 0;
	}
	else if (num.ra > 0 && num.rb > 0 && num.ra == num.rb)
	{
		num.rr = num.ra;
		num.ra = 0;
		num.rb = 0;
	}
	else
		num.rr = 0;
	return (num);
}

t_num	unit_rev_rotate(t_num num)
{
	if (num.rra > num.rrb && num.rra > 0 && num.rrb > 0)
	{
		num.rrr = num.rrb;
		num.rra = num.rra - num.rrb;
		num.rrb = 0;
	}
	else if (num.rra < num.rrb && num.rra > 0 && num.rrb > 0)
	{
		num.rrr = num.rra;
		num.rrb = num.rrb - num.rra;
		num.rra = 0;
	}
	else if (num.rra == num.rrb && num.rra > 0 && num.rrb > 0)
	{
		num.rrr = num.rra;
		num.rra = 0;
		num.rrb = 0;
	}
	else
		num.rrr = 0;
	return (num);
}

t_num	unit_moves(t_num val)
{
	val = unit_rotate(val);
	val = unit_rev_rotate(val);
	val.total_moves = val.ra + val.rb + val.rra + \
	val.rrb + val.rr + val.rrr + 1;
	return (val);
}
