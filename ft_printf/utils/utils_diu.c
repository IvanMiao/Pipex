/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 20:49:45 by ymiao             #+#    #+#             */
/*   Updated: 2024/11/29 20:49:46 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	count_len(long int n)
{
	int			count;
	long int	copy;

	count = 0;
	copy = n;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		copy = -n;
		count += 1;
	}
	while (copy)
	{
		copy = copy / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		count;
	int		copy;

	count = count_len(n);
	copy = n;
	ans = (char *)malloc(sizeof(char) * (count + 1));
	if (!ans)
		return (NULL);
	if (n == 0)
		ans[0] = '0';
	else if (n < 0)
		ans[0] = '-';
	ans[count] = '\0';
	while (copy)
	{
		if (copy < 0)
			ans[count - 1] = -(copy % 10) + 48;
		else
			ans[count - 1] = (copy % 10) + 48;
		copy = copy / 10;
		count--;
	}
	return (ans);
}

char	*ft_itoa_unsign(unsigned int n)
{
	char		*ans;
	int			count;
	long int	copy;

	count = count_len(n);
	copy = n;
	ans = (char *)malloc(sizeof(char) * (count + 1));
	if (!ans)
		return (NULL);
	if (n == 0)
		ans[0] = '0';
	ans[count] = '\0';
	while (copy)
	{
		ans[count - 1] = (copy % 10) + 48;
		copy = copy / 10;
		count--;
	}
	return (ans);
}
