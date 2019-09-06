/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_argv_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:05:49 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/06 19:32:29 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			validate_val(long val, char *line)
{
	if ((val = ft_atoi(line)) > MAX_INT || val <= -2147483648 ||
		(val > 0 && line[0] == '-') ||
		(val <= 0 && line[0] != '-' && line[0] != '0'))
		return (-1);
	return (0);
}

int			get_arr_len(char **arr)
{
	int		len;

	len = 0;
	while (arr[++len])
		;
	return (len);
}

t_num		*copy_argv_to_stack(char **arr, t_stack *stack)
{
	int		i;
	int		len;
	t_num	num;
	long	val;

	i = 0;
	len = get_arr_len(arr);
	stack->size = len;
	stack->arr = (t_num*)malloc(sizeof(t_num) * (stack->size));
	while (--len >= 0)
	{
		init_num(&num);
		val = ft_atoi(arr[len]);
		if (validate_val(val, arr[len]) == -1)
		{
			free(stack->arr);
			return (NULL);
		}
		num.val = val;
		num.index = i + 1;
		stack->arr[i++] = num;
	}
	stack->used_size = i;
	return (stack->arr);
}
