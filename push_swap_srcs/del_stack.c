/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:34:04 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/07 17:47:57 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_stack(t_stack *stck)
{
	if (stck->arr)
	{
		free(stck->arr);
		stck->arr = NULL;
	}
	if (stck)
	{
		free(stck);
		stck = NULL;
	}
}
