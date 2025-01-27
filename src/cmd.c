/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:26:12 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/27 22:31:13 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
