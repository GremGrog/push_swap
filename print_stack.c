/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:17:39 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/28 17:32:27 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->size - 1;
	j = a->size - 1;
	ft_printf("-----------------------\n");
	while (i >= 0 && j >= 0)
	{
		if (IS_EMPTY(a->arr[i].index) == 0)
			ft_printf("%d %{green}-20d",a->arr[i].index, a->arr[i].val);
		if (IS_EMPTY(a->arr[i].index) == -1)
			ft_printf("%-20c", '-');
		if (IS_EMPTY(b->arr[j].index) == 0)
			ft_printf("%{yellow}d", b->arr[j].val);
		if (IS_EMPTY(b->arr[j].index) == -1)
			ft_printf("%c", '-');
			ft_printf("\n");
		j--;
		i--;
	}
	ft_printf("-----------------------\n");
	ft_printf("%c %20c\n", a->name, b->name);
	ft_printf("%-4d |USED SIZE| %5d\n", a->used_size, b->used_size);
	ft_printf("-----------------------\n");
}
