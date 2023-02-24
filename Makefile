# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:42:57 by ode-cleb          #+#    #+#              #
#    Updated: 2023/02/24 16:20:51 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -I -lmlx -lXext -lX11

SRCS = srcs/main.c\

OBJS = ${SRCS:.c=.o}

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux/
MLX = $(MLX_PATH)/mlx.a

all: ${NAME}

${NAME}: ${OBJS} minilibx-linux/libmlx.a
		make -C $(LIBFT_PATH)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) 

${LIBFT}:
		$(MAKE) -sC $(LIBFT_PATH)

minilibx-linux/libmlx.a: 
		make -C minilibx-linux

clean :
	rm -rf *.o
	$(MAKE) -sC $(LIBFT_PATH) clean
	$(MAKE) -C minilibx_linux clean

fclean : clean
	rm -rf ${NAME}
	$(MAKE) -sC $(LIBFT_PATH) fclean

re : fclean all

.PHONY: all clean fclean re 
