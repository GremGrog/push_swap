# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 18:40:37 by fmasha-h          #+#    #+#              #
#    Updated: 2019/09/05 11:16:57 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

FLAGS = -Wall -Wextra -Werror -g

PUSH_SWAP_DIR_O = obj

INCLUDES =  push_swap.h -I libft/libft.h

LIBFT = libft/libft.a

PUSH_SWAP_DIR = push_swap_srcs

PUSH_SWAP_SRCS =	main.c \
					validation.c \
					create_stack.c \
					push_swap.c \
					print_stack.c \
					quick_sort.c \
					change_stack_fun.c \
					change_a_stack.c \
					change_b_stack.c \
					change_both_stacks.c \
					find_min_max.c \
					set_to_zero_stack.c \
					is_sort_checkers.c \
					search_values.c \
					count_moves.c \
					del_stack.c \
					unit_moves.c \
					kick_values.c \
					do_moves.c \

PUSH_SWAP_OBJF = $(addprefix $(PUSH_SWAP_DIR_O)/,$(patsubst %.c,%.o,$(PUSH_SWAP_SRCS)))

all: $(PUSH_SWAP)

$(PUSH_SWAP_DIR_O):
	@mkdir -p obj

$(PUSH_SWAP): $(PUSH_SWAP_DIR_O) $(PUSH_SWAP_OBJF)
	@make -C libft
	gcc $(FLAGS) $(PUSH_SWAP_OBJF) $(LIBFT) -o $(PUSH_SWAP)

$(PUSH_SWAP_DIR_O)/%.o: $(PUSH_SWAP_DIR)/%.c 
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(PUSH_SWAP_DIR_O)
	@make clean -C libft

fclean: clean
	@rm -rf $(PUSH_SWAP)
	@make fclean -C libft

re: fclean all