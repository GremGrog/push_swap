/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:16:35 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/05 10:55:05 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if ((validate_arg(argv[1])) == -1)
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
	else if (argc > 2)
	{
		if ((validate_args(++argv)) == -1)
		{
			ft_printf("Error\n");
			exit(0);
		}
	}
	if (argc >= 2)
		push_swap(argc, argv);
}
