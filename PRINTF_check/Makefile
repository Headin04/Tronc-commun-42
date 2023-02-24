# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ode-cleb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 18:06:06 by ode-cleb          #+#    #+#              #
#    Updated: 2023/01/10 18:39:24 by ode-cleb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_create_list.c\
       ft_printf_utils.c\
       ft_convert.c\
       ft_printf_utils2.c\
       ft_printf_utils3.c\

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wextra -Wall -Werror -fPIE

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)/libft.a

all : ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	cp $(LIBFT) $(NAME)
	ar rcs ${NAME} ${OBJS}

${LIBFT}:
	$(MAKE) -sC $(LIBFT_PATH)

%.o : %.c printf_test.h
	${CC} ${CFLAGS} -c $< -o $@ 
	#-I $(LIBFT)#

clean :
	rm -rf *.o
	$(MAKE) -sC $(LIBFT_PATH) clean

fclean : clean
	rm -rf ${NAME}
	$(MAKE) -sC $(LIBFT_PATH) fclean


re : fclean
	$(MAKE)

.PHONY = clean fclean re 

