/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:30:10 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/27 22:27:15 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>

# include "./ft_printf/ft_printf.h"
# include "./GNL/get_next_line.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
	char	**env;
	int		left_pipe[2];
	int		right_pipe[2];
}	t_cmd;

int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_cmd(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **cmd);
char	*all_path(char **env);
char	*sep_path(char *path, char *cmd);
char	*get_path(char **env, char **cmd);
int		exam_arg(int argc, char **argv, char **env);
t_cmd	assign_cmd(t_cmd cmd, char *now_arg, char **env);
void	free_t_cmd(t_cmd cmd);
void	ft_exec(int fd_read, int fd_write, t_cmd cmd);
void	run_heredoc(int argc, char **argv, char **env, char *limiter);

#endif