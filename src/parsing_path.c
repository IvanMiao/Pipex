/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:45:13 by ymiao             #+#    #+#             */
/*   Updated: 2025/02/27 04:27:40 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*all_path(char **env)
{
	int		i;
	char	*ans;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i])
	{
		if (ft_strlen(env[i]) > 5 && env[i][0] == 'P'
		&& env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
		{
			ans = env[i];
			ans += 5;
			return (ans);
		}
		i++;
	}
	return (NULL);
}

/**
 * Searches for a command in all PATH directories
 *
 * First checks if the command is already a full path. If not, searches through
 * each directory in PATH to find the executable file.
 *
 * @param allpath String containing all PATH directories separated by ':'
 * @param cmd Command name to search for
 * @return Full path to the executable if found, NULL if not found
 */
char	*sep_path(char *allpath, char *cmd)
{
	char	**path;
	char	*ans;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	path = ft_split((const char *)allpath, ':');
	if (!path)
		return (NULL);
	while (path[i])
	{
		ans = ft_strjoin_cmd(path[i], cmd);
		if (access(ans, F_OK | X_OK) == 0)
		{
			free_split(path);
			return (ans);
		}
		free(ans);
		i++;
	}
	free_split(path);
	return (NULL);
}
