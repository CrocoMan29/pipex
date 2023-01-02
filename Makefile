# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 04:59:21 by yismaail          #+#    #+#              #
#    Updated: 2023/01/02 07:25:47 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall #-fsanitize=address
RM		=	rm -rf
SRCS	=	libft/ft_split.c \
			libft/ft_substr.c \
			libft/get_next_line_utils.c \
			src/pipex.c \
			src/utils.c

OBJS	= ${SRCS:.c=.o}

$(NAME)	: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
		$(RM) $(OBJS) $(NAME)

fclean	: clean
		$(RM) $(NAME)

re		: fclean all