/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:57:47 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 18:20:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		validate_commands(char *line)
{
	if (ft_strcmp("ra", line) == 0)
		return (1);
	else if (ft_strcmp("rra", line) == 0)
		return (2);
	else if (ft_strcmp("rb", line) == 0)
		return (3);
	else if (ft_strcmp("rrb", line) == 0)
		return (4);
	else if (ft_strcmp("sa", line) == 0)
		return (5);
	else if (ft_strcmp("sb", line) == 0)
		return (6);
	else if (ft_strcmp("pa", line) == 0)
		return (7);
	else if (ft_strcmp("pb", line) == 0)
		return (8);
	else if (ft_strcmp("rr", line) == 0)
		return (9);
	else if (ft_strcmp("rrr", line) == 0)
		return (10);
	else
		return (-1);
}