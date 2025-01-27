/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:45:13 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/21 16:39:47 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*all_path(char **env)
{
	int		i;
	char	*ans;

	i = 0;
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

char	*sep_path(char *allpath, char *cmd)
{
	char	**path;
	char	*ans;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	path = ft_split((const char *)allpath, ':');
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
