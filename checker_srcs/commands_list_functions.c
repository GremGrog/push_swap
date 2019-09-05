/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_list_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:57:49 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 18:21:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_commands	*choose_fun_for_one(t_commands *elem, int fun)
{
	if (fun == 1)
		elem->fun_for_a = rotate_a;
	if (fun == 2)
		elem->fun_for_a = rev_rotate_a;
	if (fun == 3)
		elem->fun_for_b = rotate_b;
	if (fun == 4)
		elem->fun_for_b = rev_rotate_b;
	if (fun == 5)
		elem->fun_for_a = swap_a;
	if (fun == 6)
		elem->fun_for_b = swap_b;
	return (elem);
}

t_commands	*choose_fun_for_two(t_commands *elem, int fun)
{
	if (fun == 7)
		elem->fun_for_two = push_a;
	if (fun == 8)
		elem->fun_for_two = push_b;
	if (fun == 9)
		elem->fun_for_two = rotate_rr;
	if (fun == 10)
		elem->fun_for_two = rev_rotate_r;
	return (elem);
}


t_commands	*choose_fun(t_commands *elem, int fun)
{
	if (fun >= 1 && fun <= 6)
		return (choose_fun_for_one(elem, fun));
	else
		return (choose_fun_for_two(elem, fun));
}

t_commands	*add_command(t_commands *head, char *line, int fun)
{
	t_commands	*elem;
	t_commands	*buf;

	buf = head;
	if (head->command == NULL)
	{
		head->command = ft_strdup(line);
		head->fun_for_a = NULL;
		head->fun_for_b = NULL;
		head->fun_for_two = NULL;
		head = choose_fun(head, fun);
		return (head);
	}
	else
	{
		while (buf->next)
			buf = buf->next;
		elem = (t_commands*)malloc(sizeof(t_commands));
		elem->command = ft_strdup(line);
		elem->next = NULL;
		buf->next = elem;
		elem->fun_for_a = NULL;
		elem->fun_for_b = NULL;
		elem->fun_for_two = NULL;
		elem = choose_fun(elem, fun);
		return (head);
	}
	return (NULL);
}


void	delete_commands_list(t_commands *head)
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