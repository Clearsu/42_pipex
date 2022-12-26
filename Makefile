# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 20:40:49 by jincpark          #+#    #+#              #
#    Updated: 2022/11/03 17:06:51 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
FLAGS	= -Wall -Wextra -Werror -I .
DEBUG_OPT	= -g3 -fsanitize=address

MAN_SRCS	=	main.c \
		  		pipex.c \
		  		parse.c \
		  		free.c \
				ft_printf.c \
				ft_printf_utils_nbr.c \
				ft_printf_utils_str.c \
				format_char.c \
				format_hexa.c \
				format_nbr.c \
				ft_split.c \
				ft_strncmp.c \
				get_next_line_utils.c \
				ft_error.c \
				arg_check.c

BNS_SRCS	= 	main_bonus.c \
		  		pipex_bonus.c \
				here_doc_bonus.c \
		  		parse.c \
		  		free.c \
		  		ft_printf.c \
		  		ft_printf_utils_nbr.c \
		  		ft_printf_utils_str.c \
		  		format_char.c \
		  		format_hexa.c \
		  		format_nbr.c \
		  		ft_split.c \
		  		ft_strncmp.c \
		  		get_next_line.c \
		  		get_next_line_utils.c \
		  		ft_error.c \
		  		arg_check_bonus.c

MAN_OBJS	= $(MAN_SRCS:%.c=%.o)
BNS_OBJS	= $(BNS_SRCS:%.c=%.o)

ifeq ($(DEBUG_FLAG), 1)
	FLAGS += $(DEBUG_OPT)
endif

ifdef IF_BONUS
	OBJS = $(BNS_OBJS)
else
	OBJS = $(MAN_OBJS)
endif

%.o	:	%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $^ -o $@

all	:	$(NAME)

clean	:
	rm -f $(MAN_OBJS) $(BNS_OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

bonus	:
	@$(MAKE) IF_BONUS=1 all

debug	:
	@$(MAKE) DEBUG_FLAG=1 all

bonusdebug	:
	@$(MAKE) IF_BONUS=1 DEBUG_FLAG=1 all

.PHONY	:	all clean fclean re bonus debug bonusdebug
