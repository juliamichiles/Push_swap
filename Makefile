# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 18:34:35 by juliatav          #+#    #+#              #
#    Updated: 2026/01/16 18:34:59 by juliatav         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= cc
CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES = -Iinclude -I$(LIBFT_DIR)
SRCS =  srcs/main.c \
	srcs/cost.c \
	srcs/helpers.c \
	srcs/list_utils.c \
	srcs/list_utils_2.c \
	srcs/small_stacks.c \
	srcs/validate.c \
	srcs/operations/push.c \
	srcs/operations/rev_rotate.c \
	srcs/operations/rotate.c \
	srcs/operations/swap.c

OBJS	= $(SRCS:.c=.o)


all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o  $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
