# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 18:21:39 by ymiao             #+#    #+#              #
#    Updated: 2024/12/02 16:22:54 by ymiao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libftprintf.a

SRC		:= ft_printf.c analyse_format.c \
			utils/utils_cs.c utils/utils_diu.c \
			utils/utils_p.c utils/utils_xX.c
OBJS	:= $(SRC:%.c=%.o)

FLAGS	:= -Wall -Werror -Wextra

all : $(NAME) clean
	@echo "---libftprintf.a created---"

$(NAME) : $(OBJS)
	@ar rc $@ $(OBJS)

%.o : %.c
	@cc $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 
