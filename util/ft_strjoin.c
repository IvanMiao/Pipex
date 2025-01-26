/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:22:00 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/19 18:10:48 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strjoin_cmd(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*p;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	p = malloc(sizeof(char) * (len_s1 + len_s2 + 2));
	if (!p)
		return (NULL);
	while (i < len_s1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '/';
	i++;
	while (i < len_s1 + len_s2 + 1)
	{
		p[i] = s2[i - len_s1 -1];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char 	*p;

	s1 = "";
	s2 = "";
	p = ft_strjoin(s1, s2);
	printf("%s\n%s\n%s", s1, s2, p);
	return 0;
}
*/
