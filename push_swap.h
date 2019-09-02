/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 18:15:44 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/02 19:06:35 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

# define IS_EMPTY(index) ((index == -1) ? -1 : 0)

 typedef struct s_num
 {
	 int	val;
	 int	index;
	 int	ra;
	 int	rb;
	 int	rr;
	 int	rra;
	 int	rrb;
	 int	rrr;
	 int	swap;
	 int	total_moves;
 }				t_num;
 

typedef struct s_stack
{
	t_num	*arr;
	int		size;
	int		used_size;
	int		min;
	int		max;
	char	name;
}				t_stack;

int			validate_args(char **arr);
int			validate_arg(char *str);
t_stack		*create_argv_stack(int argc, char **argv);
void		push_swap(int argc, char **argv);
void		swap(int *a, int *b);
void		quick_sort(t_num *arr, int low, int high);
t_stack		*create_second_stack(t_stack *a);
void		set_to_zero_moves(t_num *num);
void		set_to_zero_stack(t_stack *b);
void		print_stack(t_stack *a, t_stack *b);

void		swap_top(t_stack *stck);
void		swap_a(t_stack *a);
void		swap_b(t_stack *b);
void		swap_ss(t_stack *a, t_stack *b);

void		push_a(t_stack *a, t_stack *b);
void		push_b(t_stack *a, t_stack *b);

void		rotate_stck(t_stack *stck);
void		rotate_a(t_stack *a);
void		rotate_b(t_stack *b);
void		rotate_rr(t_stack *a, t_stack *b);

void		rev_rotate_stck(t_stack *stck);
void		rev_rotate_a(t_stack *a);
void		rev_rotate_b(t_stack *a);
void		rev_rotate_r(t_stack *a, t_stack *b);

void		get_min_max(t_stack *stck);
int			find_max(t_stack *st);
int			find_min(t_stack *st);
void		count_moves(t_stack *a, t_stack *b);

int			is_less_sort(t_stack *a, int med);
int			is_more_sort(t_stack *a, int med);
int			is_range_sort(t_stack *a, int bottom, int top);

int			search_less_values(t_stack *stck, int val);
int			search_less_val(t_stack *stck, int val);
int			search_val(t_stack *stck, int val);
int			find_aver_val(t_stack *a);