# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2023/01/13 20:21:22 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m

# Executable and compilation
NAME			= push_swap

SRC_DIR			= ./srcs/
SRCS			= ft_args_checker.c \
		  		ft_args_parser.c \
		  		ft_args_process.c \
				ft_instructions.c \
		  		ft_other_utils.c \
		  		ft_sort_utils.c \
				ft_sort_algorithm.c \
				ft_sort_process.c \
		  		push_swap.c

LIBFT_LIB		= ${SRC_DIR}libft/libft.a
LIBFT_LIB_DIR	= ${SRC_DIR}libft

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I $(LIBFT_LIB_DIR)/includes/
RM				= rm -rf

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all: 			$(NAME)

$(NAME): 		${LIBFT_LIB} $(OBJS)
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were made ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling project...${GREY}"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}$(NAME)${RESET} compiled ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

$(LIBFT_LIB_DIR):
	@$(MAKE) -C $(LIBFT_LIB_DIR)

${OBJS}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Creating objects directory...${GREY}"
	@mkdir ${OBJ_DIR}

${LIBFT_LIB}:
	@make -C ${LIBFT_LIB_DIR}

clean:
	@$(MAKE) clean -C $(LIBFT_LIB_DIR)
	@${RM} ${OBJ_DIR}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.${GREY}"

fclean: 		clean
	@$(MAKE) fclean -C $(LIBFT_LIB_DIR)
	@${RM} ${NAME}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

re: fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re