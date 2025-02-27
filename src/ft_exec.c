/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:30:50 by ymiao             #+#    #+#             */
/*   Updated: 2025/02/27 04:29:04 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/**
 * Executes a command with input/output redirection
 *
 * Creates a child process using fork() and sets up proper file descriptors:
 * 1. Redirects stdin to fd_read
 * 2. Redirects stdout to fd_write
 * 3. Executes the command with execve()
 * 4. Parent process waits for child to complete
 *
 * @param fd_read File descriptor to use as command's input
 * @param fd_write File descriptor to use as command's output
 * @param cmd Command structure with execution details
 */
void	ft_exec(int fd_read, int fd_write, t_cmd cmd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		return ;
	}
	if (pid == 0)
	{
		// Set up redirections in child process
		if (fd_read != STDIN_FILENO)
		{
			dup2(fd_read, STDIN_FILENO);
			close(fd_read);
		}
		if (fd_write != STDOUT_FILENO)
		{
			dup2(fd_write, STDOUT_FILENO);
			close(fd_write);
		}
		// Close unused pipes
		close(cmd.right_pipe[0]);
		close(cmd.right_pipe[1]);
		if (execve(cmd.path, cmd.cmd, cmd.env) == -1)
		{
			perror("execve");
			free_t_cmd(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Parent process
		close(fd_read);  // Parent doesn't need these file descriptors anymore
		close(fd_write);
		waitpid(pid, &status, 0);
	}
}
