# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 17:21:57 by ymiao             #+#    #+#              #
#    Updated: 2025/01/21 19:45:13 by ymiao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex

CFLAGS	:= -Wall -Werror -Wextra

SRC		:= pipex.c \
			util/free_split.c util/parsing_path.c \
			util/ft_split.c util/ft_strjoin.c
SRC_PLUS	:= ft_printf/libftprintf.a
OBJS	:= $(SRC:%.c=%.o)

SRC_BONUS	:= bonus/pipex_bonus.c \
				util/free_split.c util/parsing_path.c \
				util/ft_split.c util/ft_strjoin.c \
				bonus/parsing/parsing_argc.c bonus/parsing/here_doc.c \
				bonus/parsing/cmd.c bonus/GNL/get_next_line.c \
				bonus/GNL/get_next_line_utils.c
OBJS_BONUS	:= $(SRC_BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRC)
	@make all -C ft_printf
	gcc $(CFLAGS) $(SRC) $(SRC_PLUS) -o $@

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

bonus : .bonus

.bonus : $(SRC_BONUS)
	@make all -C ft_printf
	gcc $(CFLAGS) ${SRC_BONUS} $(SRC_PLUS) -o pipex_bonus
	@touch .bonus

test : $(NAME)
	./pipex infile_not_exist cat wc outfile_not_exist; ls
	rm outfile_not_exist
	./pipex infile cat wc outfile_not_exist; ls
	rm outfile_not_exist
	./pipex infile_not_exist cat wc outfile
	./pipex infile cat wc outfile
	./pipex infile_not_exist command1

test_val : $(NAME)
	valgrind ./pipex infile_not_exist cat wc outfile_not_exist
	rm outfile_not_exist
	valgrind ./pipex infile cat wc outfile_not_exist
	rm outfile_not_exist
	valgrind ./pipex infile_not_exist cat wc outfile
	valgrind ./pipex infile cat wc outfile
	valgrind ./pipex infile_not_exist command1


clean :
	rm -rf $(OBJS) ${OBJS_BONUS} .bonus

fclean : clean
	rm -rf $(NAME) pipex_bonus

re : fclean all

.PHONY: all clean fclean re bonus
