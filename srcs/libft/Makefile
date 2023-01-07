# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:45:32 by bsoubaig          #+#    #+#              #
#    Updated: 2023/01/07 10:56:09 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE			= \033[38;5;141m
GREEN			= \033[38;5;46m
RED				= \033[0;31m
GREY			= \033[38;5;240m
RESET			= \033[0m
BOLD			= \033[1m

NAME		  	= libft.a

SRC_DIR			= ./srcs/
SRCS			= libft/ft_atoi.c \
			    libft/ft_bzero.c \
			    libft/ft_calloc.c \
			    libft/ft_isalnum.c \
			    libft/ft_isalpha.c \
			    libft/ft_isascii.c \
			    libft/ft_isdigit.c \
			    libft/ft_isprint.c \
			    libft/ft_itoa.c \
			    libft/ft_memchr.c \
			    libft/ft_memcmp.c \
			    libft/ft_memcpy.c \
			    libft/ft_memmove.c \
			    libft/ft_memset.c \
			    libft/ft_putchar_fd.c \
			    libft/ft_putendl_fd.c \
			    libft/ft_putnbr_fd.c \
			    libft/ft_putstr_fd.c \
			    libft/ft_split.c \
			    libft/ft_strchr.c \
			    libft/ft_strdup.c \
			    libft/ft_striteri.c \
			    libft/ft_strjoin.c \
			    libft/ft_strlcat.c \
			    libft/ft_strlcpy.c \
			    libft/ft_strlen.c \
			    libft/ft_strmapi.c \
			    libft/ft_strncmp.c \
			    libft/ft_strnstr.c \
			    libft/ft_strrchr.c \
			    libft/ft_strtrim.c \
			    libft/ft_substr.c \
			    libft/ft_tolower.c \
			    libft/ft_toupper.c \
				libft/ft_lstnew.c \
				libft/ft_lstadd_front.c \
				libft/ft_lstadd_back.c \
				libft/ft_lstsize.c \
				libft/ft_lstlast.c \
				libft/ft_lstdelone.c \
				libft/ft_lstclear.c \
				libft/ft_lstiter.c \
				libft/ft_lstmap.c \
				ft_printf/ft_printf.c \
				ft_printf/ft_parser.c \
				ft_printf/ft_putchar.c \
				ft_printf/ft_putnbr.c \
				ft_printf/ft_puthexnbr.c \
				ft_printf/ft_putpointer.c \
				ft_printf/ft_putstr.c \
				ft_printf/ft_putunsigned.c

OBJ_DIR			= ./objs/
OBJS			= ${addprefix ${OBJ_DIR}, ${SRCS:.c=.o}}

RM			  	= rm -rf
CC			  	= gcc
CFLAGS		 	= -Wall -Wextra -Werror

${OBJ_DIR}%.o:	${SRC_DIR}%.c
	@${CC} ${CFLAGS} -I${SRC_DIR} -c $< -o $@

all:			${NAME}

${NAME}: 		${OBJS}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were made ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Compiling library binaries...${GREY}"
	@ar rcs ${NAME} ${OBJS}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Library compiled ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

${OBJS}:		| ${OBJ_DIR}

${OBJ_DIR}:
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Creating objects directory...${GREY}"
	@mkdir ${OBJ_DIR}
	@mkdir ${OBJ_DIR}/libft
	@mkdir ${OBJ_DIR}/ft_printf

clean:
	@${RM} ${OBJ_DIR}
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.${GREY}"

fclean:			clean
	@${RM} ${NAME}
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"
	@echo "${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}"
	@echo "${RESET}${GREY}────────────────────────────────────────────────────────────────────────────"

re: 			fclean all

.SILENT: all clean fclean re
.PHONY: all clean fclean re