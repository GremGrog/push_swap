/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:53:13 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/08/24 16:32:43 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] && str[i] == ' ') || str[i] == '\t')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	return (i);
}

int	validate_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if ((validate_arg(arr[i])) == (-1))
			return (-1);
		i++;
	}
	return (i);
}