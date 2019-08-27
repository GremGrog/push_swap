/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:48:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/27 20:12:31 by fmasha-h         ###   ########.fr       */
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
			ft_printf("%d %{green}-15d",a->arr[i].index, a->arr[i].val);
		if (IS_EMPTY(a->arr[i].index) == -1)
			ft_printf("%-17c", '-');
		if (IS_EMPTY(b->arr[j].index) == 0)
			ft_printf("%d %{yellow}d", b->arr[j].index, b->arr[j].val);
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

void    push_swap(int argc, char **argv)
{
    t_stack     *a;
	t_stack		*b;

    a = create_argv_stack(argc, argv);
	b = create_second_stack(a->size);
	print_stack(a, b);
	// swap_a(a);
	// print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
	rev_rotate_a(a);
	print_stack(a, b);
	// push_b(a, b);
	// print_stack(a, b);
	// swap_b(b);
	// print_stack(a, b);
	// swap_ss(a, b);
	// print_stack(a, b);
	// rotate_b(b);
	// print_stack(a, b);
	// rotate_rr(a, b);
	// print_stack(a, b);
	// b = copy_stack(a);
    //  for (int i = a->size - 1; i >= 0; i--)
    //     ft_printf("%d\n", a->arr[i]);
    // quick_sort(a->arr, 0, a->size - 1);
    // for (int i = a->size - 1; i >= 0; i--)
    //    ft_printf("S%d\n", a->arr[i]);
}