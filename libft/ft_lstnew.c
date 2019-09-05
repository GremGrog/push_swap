/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:36:26 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 15:13:30 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list) * (content_size + 1))))
		return (NULL);
	else
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = (t_list *)malloc(sizeof(t_list) * (content_size + 1));
			if (!(list->content))
			{
				free(list);
				return (NULL);
			}
			ft_memcpy(list->content, content, content_size + 1);
			list->content_size = content_size + 1;
		}
	}
	list->next = NULL;
	return (list);
}
