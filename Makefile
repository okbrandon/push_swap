# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2022/12/27 20:32:09 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
PURPLE		= \033[38;5;141m
GREEN		= \033[38;5;46m
RED			= \033[0;31m
GREY		= \033[38;5;240m
RESET		= \033[0m

# Executable and compilation
NAME		= push_swap
SRCS		= srcs/ft_args_checker.c \
		  	srcs/ft_args_parser.c \
		  	srcs/ft_args_process.c \
			srcs/ft_instructions.c \
		  	srcs/ft_other_utils.c \
		  	srcs/ft_sort_utils.c \
			srcs/ft_sort_algorithm.c \
		  	srcs/ft_sort_process.c \
		  	srcs/push_swap.c
OBJS		= $(SRCS:.c=.o)
LIBFT_PATH	= ./libft/
LIBFT_RULE	= libft/libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I $(LIBFT_PATH)includes/
RM			= rm -f

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT_RULE) $(OBJS)
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: $(NAME) objects were made.$(GREY)"
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Compiling $(NAME)...$(GREY)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_PATH)libft.a
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: $(GREEN)$(NAME) has been compiled!"

$(LIBFT_RULE):
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Compiling libft & ft_printf...$(GREY)"
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: $(GREEN)libft & ft_printf were compiled!$(GREY)"

clean:
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Cleaning libft & ft_printf objects...$(GREY)"
	@$(MAKE) clean -C $(LIBFT_PATH)
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Cleaning $(NAME) objects...$(GREY)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Cleaning libft & ft_printf...$(GREY)"
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(RESET)[$(PURPLE)$(NAME)$(RESET)]: Cleaning $(NAME)...$(GREY)"
	$(RM) $(NAME)

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re