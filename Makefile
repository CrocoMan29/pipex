# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 04:59:21 by yismaail          #+#    #+#              #
#    Updated: 2023/01/07 16:33:12 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall #-fsanitize=address
RM			=	rm -rf
SRCS		=	src/pipex.c \
				src/utils.c \
				libft/ft_split.c \
				libft/ft_substr.c \
				libft/help.c \
				libft/utils.c \
				
SRCS_BONUS	=	bonus/pipex_bonus.c \
				bonus/utils_bonus.c \
				bonus/get_next_line_bonus.c \
				bonus/get_next_line_utils_bonus.c \
				libft/ft_split.c \
				libft/ft_substr.c \
				libft/help.c \
				libft/utils.c \
				
OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

$(NAME)		: $(SRCS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all			:	$(NAME)

clean		:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

bonus 		: $(SRCS_BONUS)
			$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)