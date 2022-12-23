# **************************************************************************** #
#                                                                              #
#    *                                                     :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeham <yeham@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 18:40:57 by yeham             #+#    #+#              #
#    Updated: 2022/09/30 19:40:20 by yeham            ###   ########.fr        #
#                                                                              #
# *************************************************************************** #

NAME = push_swap

BO_NAME = checker

SRCS = push_swap.c data.c data2.c ft_atoi.c get_clear.c greedy.c greedy_utils.c\
		hard.c linked_stack.c main_utils.c rrrrr.c quick_pivot.c\

BNS_SRCS = checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\
		stack_bonus.c utils_bonus.c data_bonus.c data2_bonus.c data3_bonus.c\
		atoi_bonus.c get_clear_bonus.c\

OBJS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BNS_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) $^ -o $@

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	make clean
	rm -f $(NAME) $(BO_NAME)

re : 
	make fclean
	make all

bonus : $(BO_NAME)
$(BO_NAME): $(BONUS_OBJS)
	cc $(CFLAGS) $^ -o $@

.PHONY : all clean fclean re bonus
