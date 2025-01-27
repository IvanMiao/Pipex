# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/22 17:21:57 by ymiao             #+#    #+#              #
#    Updated: 2025/01/27 22:29:57 by ymiao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex

CFLAGS	:= -Wall -Werror -Wextra

SRC		:= pipex.c \
				src/free_split.c src/parsing_path.c \
				src/ft_split.c src/ft_strjoin.c \
				src/parsing_argc.c src/here_doc.c src/cmd.c \
				GNL/get_next_line.c GNL/get_next_line_utils.c
SRC_PLUS	:= ft_printf/libftprintf.a
OBJS	:= $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRC)
	@make all -C ft_printf
	gcc $(CFLAGS) $(SRC) $(SRC_PLUS) -o $@

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

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
	rm -rf $(OBJS) $(SRC_PLUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
