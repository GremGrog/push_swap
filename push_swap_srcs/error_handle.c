/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:37 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/10 13:44:00 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_errors(t_stack *a)
{
	if (is_it_dup(a) == 1 || (a != NULL && a->arr == NULL))
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (a == NULL || a->used_size == 1)
		return (-1);
	return (0);
}
