/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:49:38 by ymiao             #+#    #+#             */
/*   Updated: 2024/11/30 18:48:01 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_len(unsigned long p)
{
	unsigned long	copy;
	int				count;

	if (p == 0)
		return (1);
	copy = p;
	count = 0;
	while (copy)
	{
		count++;
		copy = copy / 16;
	}
	return (count);
}

char	*ft_itoa_pointer(unsigned long p)
{
	int		count;
	char	*hexnum;
	char	*ans;

	hexnum = "0123456789abcdef";
	count = count_len(p);
	if (p == 0)
	{
		ans = "(nil)";
		return (ans);
	}
	ans = malloc(sizeof(char) * (count + 3));
	if (!ans)
		return (NULL);
	ans[count + 2] = '\0';
	while (p)
	{
		ans[count + 1] = hexnum[p % 16];
		count--;
		p = p / 16;
	}
	ans[0] = '0';
	ans[1] = 'x';
	return (ans);
}

/*
int	main(void)
{
	int	i = 2;
	void *p = &i;
	unsigned long ptr = (unsigned long)p;
	char *str = ft_itoa_pointer(ptr);
	
	printf("%p\n", p);
	printf("%s\n", str);

	return 0;
}
*/
