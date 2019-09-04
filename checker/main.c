/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:59:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/04 19:32:12 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	read_input(void)
{
	char	*input;

	while ((get_next_line(1, &input)) > 0)
		;
	ft_printf("%s", input);
}

void	checker(void)
{
	// t_stack	*a;
	// t_stack	*b;

	// a = create_argv_stack(argc, argv);
	// if (is_it_sort(a) == 0 || (is_it_dup(a) == 1))
	// {
	// 	del_stack(a);
	// 	return ;
	// }
	// b = create_second_stack(a);
	// set_to_zero_stack(b);
	read_input();
}

int	main(int argc, char **argv)
{
	if (!argv)
		return -1;
	// if (argc == 2)
	// {
	// 	if ((validate_arg(argv[1])) == -1)
	// 	{
	// 		ft_printf("Error\n");
	// 		exit(0);
	// 	}
	// }
	// else if (argc > 2)
	// {
	// 	if ((validate_args(++argv)) == -1)
	// 	{
	// 		ft_printf("Error\n");
	// 		exit(0);
	// 	}
	// }
	if (argc >= 2)
		checker();
}