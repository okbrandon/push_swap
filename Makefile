# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 14:21:53 by bsoubaig          #+#    #+#              #
#    Updated: 2023/04/18 10:59:18 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors constants
PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m
CLEAR			= \r\033[K

# Executable and compilation
NAME			= push_swap
BONUS_NAME		= checker

SRC_DIR			= ./srcs/
SRCS			= ft_args_checker.c \
		  		ft_args_parser.c \
		  		ft_args_process.c \
				ft_instructions_printer.c \
				ft_instructions.c \
		  		ft_other_utils.c \
		  		ft_sort_utils.c \
				ft_sort_algorithm.c \
				ft_sort_process.c \
				ft_sort_helper.c \
		  		push_swap.c

SRCS_BONUS		= bonus/checker_bonus.c \
				  bonus/ft_args_checker_bonus.c \
				  bonus/ft_args_parser_bonus.c \
				  bonus/ft_args_process_bonus.c \
				  bonus/ft_other_utils_bonus.c \
				  bonus/ft_instructions_bonus.c \
				  bonus/ft_action_handler_bonus.c \
				  bonus/ft_checker_process_bonus.c

LIBFT_LIB		= libft/libft.a
LIBFT_LIB_DIR	= libft

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}
OBJS_BONUS		= ${addprefix ${OBJ_DIR}, ${SRCS_BONUS:.c=.o}}

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I $(LIBFT_LIB_DIR)/includes/
RM				= rm -rf

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling ${GREEN}%s${RESET}...${GREY}" ${notdir $<}
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all: 			$(NAME)

$(NAME): 		${LIBFT_LIB} $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

$(BONUS_NAME): 	${LIBFT_LIB} $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME) $(LIBFT_LIB)
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${BONUS_NAME}${RESET}]: ${RED}${BOLD}${BONUS_NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

$(LIBFT_LIB_DIR):
	@$(MAKE) -C $(LIBFT_LIB_DIR)

${OBJS}:		| ${OBJ_DIR}

${OBJS_BONUS}:	| ${OBJ_DIR}

${OBJ_DIR}:
	@mkdir ${OBJ_DIR}
	@mkdir ${OBJ_DIR}/bonus

${LIBFT_LIB}:
	@make -C ${LIBFT_LIB_DIR}

bonus: 			${BONUS_NAME}

clean:
	@$(MAKE) clean -C $(LIBFT_LIB_DIR)
	@${RM} ${OBJ_DIR}
	@printf "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

fclean: 		clean
	@$(MAKE) fclean -C $(LIBFT_LIB_DIR)
	@${RM} ${NAME}
	@${RM} ${BONUS_NAME}
	@printf "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

re: fclean all

.SILENT: all clean fclean re bonus
.PHONY: all clean fclean re bonus