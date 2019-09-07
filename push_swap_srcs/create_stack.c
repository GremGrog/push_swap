/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:46:33 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/07 12:05:13 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		set_to_zero_moves(t_num *n)
{
	n->ra = 0;
	n->rb = 0;
	n->rr = 0;
	n->rra = 0;
	n->rrb = 0;
	n->rrr = 0;
	n->swap = 0;
	n->total_moves = 0;
}

void		init_num(t_num *n)
{
	n->val = -1;
	n->index = -1;
	n->ra = 0;
	n->rb = 0;
	n->rr = 0;
	n->rra = 0;
	n->rrb = 0;
	n->rrr = 0;
	n->swap = 0;
	n->total_moves = 0;
}

void		del_arrays(char **arr, t_stack *a)
{
	del_matrix(arr);
	free(arr);
	free(a);
	ft_printf("Error\n");
}

t_stack		*create_argv_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**arr;

	arr = NULL;
	a = (t_stack*)malloc(sizeof(t_stack));
	if (argc == 2)
	{
		arr = ft_strsplit(argv[1], ' ');
		a->arr = copy_argv_to_stack(arr, a);
	}
	else if (argc > 2)
		a->arr = copy_argv_to_stack(argv, a);
	if (a->arr == NULL)
	{
		del_arrays(arr, a);
		return (NULL);
	}
	a->name = 'a';
	get_min_max(a);
	if (arr)
		del_matrix(arr);
	free(arr);
	return (a);
}

t_stack		*create_second_stack(t_stack *a)
{
	t_stack		*b;
	int			i;
	t_num		num;

	i = a->size - 1;
	b = (t_stack*)malloc(sizeof(t_stack));
	b->arr = (t_num*)malloc(sizeof(t_num) * a->size);
	b->name = 'b';
	b->used_size = 0;
	b->size = a->size;
	b->min = -1;
	b->max = -1;
	while (i >= 0)
	{
		init_num(&num);
		b->arr[i] = num;
		b->arr[i].val = a->arr[i].val;
		b->arr[i].index = a->arr[i].index;
		i--;
		b->used_size++;
	}
	return (b);
}
