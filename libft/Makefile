# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsoubaig <bsoubaig@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:45:32 by bsoubaig          #+#    #+#              #
#    Updated: 2022/12/03 14:32:25 by bsoubaig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		  = libft.a
SOURCES		  = srcs/libft/ft_atoi.c \
			    srcs/libft/ft_bzero.c \
			    srcs/libft/ft_calloc.c \
			    srcs/libft/ft_isalnum.c \
			    srcs/libft/ft_isalpha.c \
			    srcs/libft/ft_isascii.c \
			    srcs/libft/ft_isdigit.c \
			    srcs/libft/ft_isprint.c \
			    srcs/libft/ft_itoa.c \
			    srcs/libft/ft_memchr.c \
			    srcs/libft/ft_memcmp.c \
			    srcs/libft/ft_memcpy.c \
			    srcs/libft/ft_memmove.c \
			    srcs/libft/ft_memset.c \
			    srcs/libft/ft_putchar_fd.c \
			    srcs/libft/ft_putendl_fd.c \
			    srcs/libft/ft_putnbr_fd.c \
			    srcs/libft/ft_putstr_fd.c \
			    srcs/libft/ft_split.c \
			    srcs/libft/ft_strchr.c \
			    srcs/libft/ft_strdup.c \
			    srcs/libft/ft_striteri.c \
			    srcs/libft/ft_strjoin.c \
			    srcs/libft/ft_strlcat.c \
			    srcs/libft/ft_strlcpy.c \
			    srcs/libft/ft_strlen.c \
			    srcs/libft/ft_strmapi.c \
			    srcs/libft/ft_strncmp.c \
			    srcs/libft/ft_strnstr.c \
			    srcs/libft/ft_strrchr.c \
			    srcs/libft/ft_strtrim.c \
			    srcs/libft/ft_substr.c \
			    srcs/libft/ft_tolower.c \
			    srcs/libft/ft_toupper.c \
				srcs/ft_printf/ft_printf.c \
				srcs/ft_printf/ft_parser.c \
				srcs/ft_printf/ft_putchar.c \
				srcs/ft_printf/ft_putnbr.c \
				srcs/ft_printf/ft_puthexnbr.c \
				srcs/ft_printf/ft_putpointer.c \
				srcs/ft_printf/ft_putstr.c \
				srcs/ft_printf/ft_putunsigned.c
BONUS_SOURCES = srcs/libft/ft_lstnew.c \
				srcs/libft/ft_lstadd_front.c \
				srcs/libft/ft_lstadd_back.c \
				srcs/libft/ft_lstsize.c \
				srcs/libft/ft_lstlast.c \
				srcs/libft/ft_lstdelone.c \
				srcs/libft/ft_lstclear.c \
				srcs/libft/ft_lstiter.c \
				srcs/libft/ft_lstmap.c
OBJECTS		  = ${SOURCES:.c=.o}
BONUS_OBJECTS = ${BONUS_SOURCES:.c=.o}
RM			  = rm -f
CC			  = gcc
CFLAGS		  = -Wall -Wextra -Werror

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

bonus: 		${OBJECTS} ${BONUS_OBJECTS}
	ar rcs ${NAME} ${OBJECTS} ${BONUS_OBJECTS}

clean:
	${RM} ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
