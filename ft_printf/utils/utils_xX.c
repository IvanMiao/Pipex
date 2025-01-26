/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:49:47 by ymiao             #+#    #+#             */
/*   Updated: 2024/11/30 17:42:28 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_len(unsigned int n)
{
	int			count;
	long int	copy;

	count = 0;
	copy = n;
	if (n == 0)
		return (1);
	while (copy)
	{
		copy = copy / 16;
		count++;
	}
	return (count);
}

char	*ft_itoa_hex_low(unsigned int n)
{
	char		*hex_num;
	char		*ans;
	int			count;

	hex_num = "0123456789abcdef";
	count = count_len(n);
	ans = (char *)malloc(sizeof(char) * (count + 1));
	if (!ans)
		return (NULL);
	if (n == 0)
		ans[0] = '0';
	ans[count] = '\0';
	while (n)
	{
		ans[count - 1] = hex_num[n % 16];
		n = n / 16;
		count--;
	}
	return (ans);
}

char	*ft_itoa_hex_up(unsigned int n)
{
	char		*hex_num;
	char		*ans;
	int			count;

	hex_num = "0123456789ABCDEF";
	count = count_len(n);
	ans = (char *)malloc(sizeof(char) * (count + 1));
	if (!ans)
		return (NULL);
	if (n == 0)
		ans[0] = '0';
	ans[count] = '\0';
	while (n)
	{
		ans[count - 1] = hex_num[n % 16];
		n = n / 16;
		count--;
	}
	return (ans);
}
