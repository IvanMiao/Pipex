/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:26:12 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/21 19:56:04 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

t_cmd	assign_cmd(t_cmd cmd, char *now_arg, char **env)
{
	pipe(cmd.right_pipe);
	cmd.cmd = ft_split(now_arg, ' ');
	cmd.path = get_path(env, cmd.cmd);
	cmd.env = env;
	return (cmd);
}

void	free_t_cmd(t_cmd cmd)
{
	if (cmd.path != cmd.cmd[0])
		free(cmd.path);
	free_split(cmd.cmd);
}

void	ft_exec(int fd_read, int fd_write, t_cmd cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("fork");
	dup2(fd_read, 0);
	dup2(fd_write, 1);
	close(fd_read);
	close(fd_write);
	if (pid == 0)
	{
		if (execve(cmd.path, cmd.cmd, cmd.env) == -1)
		{
			perror("execve");
			free_t_cmd(cmd);
		}
	}
	waitpid(pid, NULL, 0);
	return ;
}
