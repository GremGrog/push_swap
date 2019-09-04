# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/23 18:40:37 by fmasha-h          #+#    #+#              #
#    Updated: 2019/09/04 19:27:08 by fmasha-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

FLAGS = -Wall -Wextra -Werror -g

DIR_O = obj

INCLUDES =  ../push_swap.h -I ../libft/libft.h

LIBFT = ../libft/libft.a

SRCS =	main.c \

OBJF = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SRCS)))

PUSH_SWAP_O = ../obj/*.o

all: $(NAME)

$(DIR_O):
	@mkdir -p obj

$(NAME): $(DIR_O) $(OBJF)
	@make -C ../libft
	make -C ../
	gcc $(FLAGS) $(OBJF) $(LIBFT) -o $(NAME)

$(DIR_O)/%.o: ./%.c 
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(DIR_O)
	@make clean -C ../libft

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ../libft

re: fclean all