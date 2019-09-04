/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:17:28 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 16:55:07 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		partition(t_num *arr, int low, int high)
{
	int pivot;
	int i;
	int	j;

	i = (low - 1);
	pivot = arr[high].val;
	j = low;
	while (j <= high)
	{
		if (arr[j].val > pivot)
		{
			i++;
			swap(&arr[i].val, &arr[j].val);
		}
		j++;
	}
	swap(&arr[i + 1].val, &arr[high].val);
	return (i + 1);
}

void	quick_sort(t_num *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}
