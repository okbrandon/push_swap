# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2022/12/13 19:44:14 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= libft/
SRCS	= srcs/ft_args_checker.c \
		  srcs/ft_args_parser.c \
		  srcs/ft_args_process.c \
		  srcs/ft_instructions.c \
		  srcs/ft_other_utils.c \
		  srcs/ft_sort_utils.c \
		  srcs/ft_sort_process.c \
		  srcs/push_swap.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I $(LIBFT)includes/
RM		= rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)libft.a

clean:
	@$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re