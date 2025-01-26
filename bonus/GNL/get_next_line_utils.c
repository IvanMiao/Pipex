/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:16:05 by ymiao             #+#    #+#             */
/*   Updated: 2025/01/21 18:33:06 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_sizet(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	if (s == NULL)
		return (NULL);
	p = (char *)s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (*p == (char)c)
		return (p);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen_sizet(s);
	new = (char *)malloc(sizeof(char) * (len_s + 1));
	if (!new)
		return (NULL);
	while (i <= len_s)
	{
		new[i] = s[i];
		i++;
	}
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*p;

	len_s1 = ft_strlen_sizet(s1);
	len_s2 = ft_strlen_sizet(s2);
	i = -1;
	p = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!p)
		return (NULL);
	while (++i < len_s1)
		p[i] = s1[i];
	while (i < len_s1 + len_s2)
	{
		p[i] = s2[i - len_s1];
		i++;
	}
	p[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}

char	*ft_strlcpy(const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	char	*dest;

	i = 0;
	if (!src)
		return (NULL);
	len_src = ft_strlen_sizet(src);
	if (size == 0)
		return (NULL);
	if (len_src < size)
		size = len_src;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
