/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:26:12 by ymiao             #+#    #+#             */
/*   Updated: 2025/02/27 04:28:39 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/**
 * Prepares a command structure for execution
 *
 * 1. Parses the command string into an array of arguments
 * 2. Creates a new pipe for command output
 * 3. Finds the full path to the executable
 * 4. Stores environment variables for execve
 *
 * @param cmd Command structure to initialize
 * @param now_arg Command string from command line
 * @param env Environment variables array
 * @return Initialized command structure ready for execution
 */
t_cmd	assign_cmd(t_cmd cmd, char *now_arg, char **env)
{
	cmd.cmd = ft_split(now_arg, ' ');
	if (!cmd.cmd)
	{
		cmd.path = NULL;
		return (cmd);
	}
	if (pipe(cmd.right_pipe) == -1)
	{
		perror("pipe");
		free_split(cmd.cmd);
		cmd.path = NULL;
		return (cmd);
	}
	cmd.path = get_path(env, cmd.cmd);
	cmd.env = env;
	return (cmd);
}

/**
 * Frees resources used by a command structure
 *
 * Properly frees memory allocated for command execution:
 * - Frees the path string if it's not part of the cmd array
 * - Frees the array of command arguments
 */
void	free_t_cmd(t_cmd cmd)
{
	if (cmd.cmd && cmd.path && cmd.path != cmd.cmd[0])
		free(cmd.path);
	if (cmd.cmd)
		free_split(cmd.cmd);
}
