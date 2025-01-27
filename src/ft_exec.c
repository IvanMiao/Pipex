/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:30:50 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/27 22:31:58 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
