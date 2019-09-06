/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:57:49 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/06 15:21:44 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_commands	*choose_fun(t_commands *elem, int fun)
{
	if (fun == 1)
		elem->fun_for_a = rotate_stck;
	if (fun == 2)
		elem->fun_for_a = rev_rotate_stck;
	if (fun == 3)
		elem->fun_for_b = rotate_stck;
	if (fun == 4)
		elem->fun_for_b = rev_rotate_stck;
	if (fun == 5)
		elem->fun_for_a = swap_top;
	if (fun == 6)
		elem->fun_for_b = swap_top;
	if (fun == 7)
		elem->fun_for_two = push_stck_a;
	if (fun == 8)
		elem->fun_for_two = push_stck_b;
	if (fun == 9)
		elem->fun_for_two = rotate_rr_stcks;
	if (fun == 10)
		elem->fun_for_two = rev_rotate_stcks;
	if (fun == 11)
		elem->fun_for_two = swap_ss_stcks;
	return (elem);
}

t_commands	*init_list_elem(t_commands *elem)
{
	elem->fun_for_a = NULL;
	elem->fun_for_b = NULL;
	elem->fun_for_two = NULL;
	elem->next = NULL;
	return (elem);
}

t_commands	*add_command(t_commands *head, char *line, int fun)
{
	if (head->command == NULL)
	{
		head->command = ft_strdup(line);
		head = init_list_elem(head);
		head = choose_fun(head, fun);
		return (head);
	}
	return (NULL);
}

void		delete_commands_list(t_commands *head)
{
	t_commands	*buf;
	t_commands	*tmp;

	if (!head)
		return ;
	if (!head->next)
		return ;
	tmp = head->next;
	while (tmp)
	{
		buf = tmp;
		tmp = tmp->next;
		free(buf->command);
		free(buf);
	}
}
