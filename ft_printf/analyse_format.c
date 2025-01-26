/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 19:15:54 by ymiao             #+#    #+#             */
/*   Updated: 2024/12/26 17:42:11 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversions_csdi(char c, va_list *args, int count, int fd)
{
	char	*temp;

	if (c == 'c')
	{
		ft_putchar(va_arg(*args, int), fd);
		count++;
	}
	else if (c == 's')
	{
		temp = va_arg(*args, char *);
		ft_putstr(temp, fd);
		if (temp == NULL)
			temp = "(null)";
		count += ft_strlen(temp);
	}
	else if (c == 'd' || c == 'i')
	{
		temp = ft_itoa(va_arg(*args, int));
		ft_putstr(temp, fd);
		count += ft_strlen(temp);
		free(temp);
	}
	return (count);
}

int	conversions_up(char c, va_list *args, int count, int fd)
{
	char				*temp;
	unsigned int		num;
	unsigned long		num_p;

	if (c == 'u')
	{
		num = va_arg(*args, int);
		temp = ft_itoa_unsign(num);
		ft_putstr(temp, fd);
		count += ft_strlen(temp);
		free(temp);
	}
	else if (c == 'p')
	{
		num_p = va_arg(*args, unsigned long);
		temp = ft_itoa_pointer(num_p);
		ft_putstr(temp, fd);
		count += ft_strlen(temp);
		if (num_p != 0)
			free(temp);
	}
	return (count);
}

int	conversions_xxup(char c, va_list *args, int count, int fd)
{
	char				*temp;
	unsigned int		num;

	if (c == 'x')
	{
		num = va_arg(*args, int);
		temp = ft_itoa_hex_low(num);
		ft_putstr(temp, fd);
		count += ft_strlen(temp);
		free(temp);
	}
	else if (c == 'X')
	{
		num = va_arg(*args, int);
		temp = ft_itoa_hex_up(num);
		ft_putstr(temp, fd);
		count += ft_strlen(temp);
		free(temp);
	}
	else if (c == '%')
	{
		ft_putchar('%', fd);
		count++;
	}
	return (count);
}

int	analyse_format(const char *s, va_list *args, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i], fd);
			count++;
		}
		else if (s[i] == '%' && s[i + 1])
		{
			count = conversions_csdi(s[i + 1], args, count, fd);
			count = conversions_up(s[i + 1], args, count, fd);
			count = conversions_xxup(s[i + 1], args, count, fd);
			i++;
		}
		i++;
	}
	return (count);
}
