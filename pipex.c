/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:59:03 by ymiao             #+#    #+#             */
/*   Updated: 2025/02/27 04:25:33 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * Main execution loop for the pipeline process
 * 
 * Handles the execution flow based on the command's position in the pipeline:
 * - First command: reads from input file and writes to pipe
 * - Middle commands: reads from previous pipe and writes to next pipe
 * - Last command: reads from previous pipe and writes to output file
 *
 * After executing each command, saves the read end of the current pipe
 * to be used as input for the next command
 *
 * @param fd Array containing input file descriptor [0] and output file descriptor [1]
 * @param cmd Pointer to the command structure with execution details
 * @param i Current command index
 * @param argc Total number of arguments to determine last command
 */

void	pipes_mainloop(int *fd, t_cmd *cmd, int i, int argc)
{
	if (i == 2)
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

/**
 * Main execution loop for the pipeline process
 * 
 * Handles the execution flow based on the command's position in the pipeline:
 * - First command: reads from input file and writes to pipe
 * - Middle commands: reads from previous pipe and writes to next pipe
 * - Last command: reads from previous pipe and writes to output file
 *
 * After executing each command, saves the read end of the current pipe
 * to be used as input for the next command
 *
 * @param fd Array containing input file descriptor [0] and output file descriptor [1]
 * @param cmd Pointer to the command structure with execution details
 * @param i Current command index
 * @param argc Total number of arguments to determine last command
 */

void	run_pipes(int argc, char **argv, char **env)
{
	t_cmd	cmd;
	int		fd[2];
	int		i;

	i = 2;
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", strerror(errno), argv[1]);
		exit(EXIT_FAILURE);
	}
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", strerror(errno), argv[argc - 1]);
		close(fd[0]); // Close the input file before exit
		exit(EXIT_FAILURE);
	}
	while (i < argc - 1)
	{
		cmd = assign_cmd(cmd, argv[i], env);
		pipes_mainloop(fd, &cmd, i, argc);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	if (exam_arg(argc, argv, env) != 0)
		return (1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		run_heredoc(argc, argv, env, argv[2]);
	else
		run_pipes(argc, argv, env);
	return (0);
}
