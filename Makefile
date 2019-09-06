# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 18:40:37 by fmasha-h          #+#    #+#              #
#    Updated: 2019/09/06 17:06:43 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

LIB = make -C libft

FLAGS = -Wall -Wextra -Werror -g

PUSH_SWAP_DIR_O = push_swap_obj

CHECKER_DIR_O = checker_obj

INCLUDES =  push_swap.h -I libft/libft.h

LIBFT = libft/libft.a

PUSH_SWAP_DIR = push_swap_srcs

CHECKER_DIR = checker_srcs

PUSH_SWAP_MAIN = push_swap_srcs/main_push_swap.c

CHECKER_MAIN = checker_srcs/main_checker.c

PUSH_SWAP_SRCS =	push_swap.c \
					print_stack.c \
					quick_sort.c \
					find_min_max.c \
					set_to_zero_stack.c \
					is_sort_checkers.c \
					search_values.c \
					count_moves.c \
					unit_moves.c \
					kick_values.c \
					do_moves.c \
					create_stack.c \
					change_stack_fun.c \
					change_a_stack.c \
					change_b_stack.c \
					change_both_stacks.c \
					del_stack.c \
					validation.c \
					small_sort.c \
					error_handle.c \
					copy_argv_to_stack.c \

CHECKER_SRCS = 	commands_list_functions.c \
				validate_commands.c \
				change_stacks_without_output.c \

PUSH_SWAP_OBJF = $(addprefix $(PUSH_SWAP_DIR_O)/,$(patsubst %.c,%.o,$(PUSH_SWAP_SRCS)))

CHECKER_OBJF = $(addprefix $(CHECKER_DIR_O)/,$(patsubst %.c,%.o,$(CHECKER_SRCS)))

all: $(LIB) $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP_DIR_O):
	@mkdir -p push_swap_obj

$(CHECKER_DIR_O):
	@mkdir -p checker_obj

$(LIB):
	@make -C libft

$(PUSH_SWAP): $(PUSH_SWAP_DIR_O) $(PUSH_SWAP_OBJF) $(LIB)
	@gcc $(FLAGS) $(PUSH_SWAP_MAIN) $(PUSH_SWAP_OBJF) $(LIBFT) -o $(PUSH_SWAP)

$(CHECKER): $(CHECKER_DIR_O) $(CHECKER_OBJF) $(LIB)
	@gcc $(FLAGS) $(CHECKER_MAIN) $(CHECKER_OBJF) $(PUSH_SWAP_OBJF) $(LIBFT) -o $(CHECKER)

$(PUSH_SWAP_DIR_O)/%.o: $(PUSH_SWAP_DIR)/%.c 
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

$(CHECKER_DIR_O)/%.o: $(CHECKER_DIR)/%.c 
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(PUSH_SWAP_DIR_O)
	@rm -rf $(CHECKER_DIR_O)
	@make clean -C libft

fclean: clean
	@rm -rf $(PUSH_SWAP)
	@rm -rf $(CHECKER)
	@make fclean -C libft

re: fclean all