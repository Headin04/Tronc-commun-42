# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <ode-cleb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 14:42:57 by ode-cleb          #+#    #+#              #
#    Updated: 2023/03/16 12:41:19 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

		#COMMAND#

CC				= cc
MKDIR			= mkdir -p
RM				= rm -rf

		#SOURCES#

C_DIR			= src
C_FILES			= so_long.c parsing.c check_wall.c check_caracter.c check_args_name_rectangle.c backtracking.c create_window.c replace.c deal_key.c
SRCS			= $(patsubst %, $(C_DIR)/%, $(C_FILES))

		#OBJECTS#

O_DIR			= objs
O_FILES			= $(C_FILES:.c=.o)
OBJS			= $(patsubst %, $(O_DIR)/%, $(O_FILES))

		#FLAGS#

FLAGS			= -Wall -Wextra -g3 -MMD

ifeq ($(debug), true)
	FLAGS += -fsanitize=address,undefined -g3
endif

MFLAGS			= -lXext -lX11

		#INCLUDES#

INCLUDES		= -I ./minilibx-linux -I ./libft -I ./src
LIBFTPRINTF			= ./Ft_printf/libftprintf.a
MLX				= ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a

		#RULES#

all: ${NAME}

$(O_DIR):
				$(MKDIR) $(O_DIR)

$(O_DIR)/%.o: $(C_DIR)/%.c
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
				make -C ./Ft_printf all

$(MLX):
				make -C ./minilibx-linux all

$(NAME): $(O_DIR) $(OBJS) $(LIBFTPRINTF) $(MLX)
				$(CC) $(OBJS) $(FLAGS) $(MFLAGS) $(LIBFTPRINTF) $(MLX) -o $@

	
	#CLEAN#

clean :
				make -C ./Ft_printf clean
				make -C ./minilibx-linux clean
				$(RM) $(O_DIR)

fclean :
				$(RM) $(O_DIR)
				make -C ./Ft_printf fclean
				make -C ./minilibx-linux clean
				$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re 
