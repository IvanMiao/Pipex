/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:03 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/21 19:11:53 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

void	get_heredoc(char *limiter, int fd)
{
	char	*line;
	char	*lim;
	char	*retour;

	retour = ft_strdup("\n");
	lim = ft_strdup((const char *)limiter);
	lim = ft_strjoin(lim, retour);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (ft_strcmp(line, lim) == 0)
		{
			free(line);
			free(lim);
			break ;
		}
		ft_printf_fd(fd, "%s", line);
		free(line);
	}
}

void	heredoc_mainloop(int *fd, t_cmd *cmd, int i, int argc)
{
	if (i == 3)
		ft_exec(fd[0], cmd->right_pipe[1], *cmd);
	else if (i != argc - 2)
		ft_exec(cmd->left_pipe[0], cmd->right_pipe[1], *cmd);
	else
		ft_exec(cmd->left_pipe[0], fd[1], *cmd);
	if (i != argc - 2)
		cmd->left_pipe[0] = cmd->right_pipe[0];
	else
	{
		close(cmd->right_pipe[0]);
		close(cmd->right_pipe[1]);
	}
	free_t_cmd(*cmd);
}

void	run_heredoc(int argc, char **argv, char **env, char *limiter)
{
	int		fd[2];
	int		i;
	t_cmd	cmd;

	i = 3;
	fd[0] = open("./.heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	get_heredoc(limiter, fd[0]);
	close(fd[0]);
	fd[0] = open("./.heredoc.tmp", O_RDONLY);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	while (i < argc - 1)
	{
		cmd = assign_cmd(cmd, argv[i], env);
		heredoc_mainloop(fd, &cmd, i, argc);
		i++;
	}	
	unlink("./.heredoc.tmp");
}
