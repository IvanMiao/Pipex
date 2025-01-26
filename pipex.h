/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 03:34:52 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/19 18:10:53 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>

# include "ft_printf/ft_printf.h"

char	*ft_strjoin_cmd(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **cmd);
char	*all_path(char **env);
char	*sep_path(char *path, char *cmd);

#endif