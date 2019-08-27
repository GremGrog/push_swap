/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:46:33 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/27 17:43:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num		*copy_argv_to_stack(char **arr, t_stack *stack)
{
	int		i;
	int		len;
	t_num	*num;

	i = 0;
	len = 0;
	while (arr[len++])
		;
	stack->size = len - 1;
	len -= 2;
	stack->arr = (t_num*)malloc(sizeof(t_num) * (stack->size));
	while (len >= 0)
	{
		num = (t_num*)malloc(sizeof(t_num));
		num->val = ft_atoi(arr[len]);
		num->index = i;
		stack->arr[i] = *num;
		len--;
		i++;
	}
	stack->used_size = i;
	return (stack->arr);
}

t_stack		*create_argv_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**arr;

	a = (t_stack*)malloc(sizeof(t_stack));
	if (argc == 2)
	{
		arr = ft_strsplit(argv[1], ' ');
		a->arr = copy_argv_to_stack(arr, a);
	}
	else if (argc > 2)
		a->arr = copy_argv_to_stack(argv, a);
	a->name = 'a';
	return (a);
}

t_stack		*create_second_stack(int size)
{
	t_stack		*b;
	int			i;
	t_num	*num;
	
	i = 0;
	b = (t_stack*)malloc(sizeof(t_stack));
	b->arr = (t_num*)malloc(sizeof(t_num) * size);
	b->name = 'b';
	b->used_size = 0;
	b->size = size;
	while (i < size)
	{
		num = (t_num*)malloc(sizeof(t_num));
		num->val = 0;
		num->index = -1;
		b->arr[i] = *num;
		i++;
	}
	return (b);
}