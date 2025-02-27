/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:06:01 by ymiao             #+#    #+#             */
/*   Updated: 2025/02/27 04:27:06 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/**
 * Retrieves the full path to a command executable
 *
 * Searches for the command in the system paths found in environment variables.
 * Prints error message if command is not found.
 *
 * @param env Array of environment variables to search for PATH
 * @param cmd Array containing the command and its arguments
 * @return Full path to the executable if found, NULL if not found
 */
char	*get_path(char **env, char **cmd)
{
	char	*s;
	char	*ans;

	s = all_path(env);
	ans = sep_path(s, cmd[0]);
	if (ans == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: command not found: %s\n", cmd[0]);
		free_split(cmd);
		return (NULL);
	}
	return (ans);
}

/**
 * Validates command line arguments and checks if commands exist
 *
 * 1. Ensures proper number of arguments
 * 2. For each command, checks if it exists in system paths
 * 3. Handles both standard mode and here_doc mode
 *
 * @param argc Number of command line arguments
 * @param argv Array of argument strings
 * @param env Environment variables array
 * @return 0 on success, 1 on usage error, 2 on command not found
 */
int	exam_arg(int argc, char **argv, char **env)
{
	int		i;
	char	**cmd;
	char	*path;

	i = 2;
	if (argc < 5)
	{
		ft_printf_fd(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n\
or: ./pipex here_doc LIMITER cmd cmd1 file\n");
		return (1);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
		i = 3;
	while (i < argc - 1)
	{
		cmd = ft_split((const char *)argv[i], ' ');
		path = get_path(env, cmd);
		if (path == NULL)
			return (2);
		if (path != cmd[0])
			free(path);
		free_split(cmd);
		i++;
	}
	return (0);
}
