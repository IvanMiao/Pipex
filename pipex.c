/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:26:09 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/21 19:54:31 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **env, char **cmd)
{
	char	*s;
	char	*ans;

	s = all_path(env);
	ans = sep_path(s, cmd[0]);
	if (ans == NULL)
	{
		ft_printf_fd(2, "pipex: command not found: %s\n", cmd[0]);
		free_split(cmd);
		exit(127);
	}
	return (ans);
}

void	ft_exec(int fd_file, char **cmd, char **env, int in_or_out)
{
	char	*path;

	if (in_or_out == 0)
		dup2(fd_file, 0);
	else if (in_or_out == 1)
		dup2(fd_file, 1);
	close(fd_file);
	path = get_path(env, cmd);
	if (execve(path, cmd, env) == -1)
	{
		if (path != cmd[0] && path)
			free(path);
		free_split(cmd);
		perror("execve");
	}
	return ;
}

int	pipe_left(int *fd, char **argv, char **env)
{
	int		infile;
	char	**cmd;

	cmd = ft_split(argv[2], ' ');
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		ft_printf_fd(2, "pipex: no such file or directory: %s\n", argv[1]);
		free_split(cmd);
		exit(1);
	}
	ft_exec(infile, cmd, env, 0);
	return (1);
}

int	pipe_right(int *fd, char **argv, char **env)
{
	int		outfile;
	char	**cmd;

	cmd = ft_split(argv[3], ' ');
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("open");
		free_split(cmd);
		exit(1);
	}
	ft_exec(outfile, cmd, env, 1);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf_fd(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	pipe(fd);
	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
		pipe_left(fd, argv, envp);
	else
	{
		waitpid(pid, NULL, 0);
		pipe_right(fd, argv, envp);
	}
	return (1);
}
