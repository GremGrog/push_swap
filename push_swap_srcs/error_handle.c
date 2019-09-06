/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:37 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/06 17:11:05 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		check_errors(t_stack *a)
{
	if (is_it_dup(a) == 1 || (a != NULL && a->arr == NULL))
	{
		ft_printf("Error\n");
		if (a)
			del_stack(a);
		return (-1);
	}
	if (a == NULL)
		return (-1);
	return (0);
}
