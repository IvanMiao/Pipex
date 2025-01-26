/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:21:32 by ymiao             #+#    #+#             */
/*   Updated: 2024/12/26 17:45:36 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *s, ...)
{
	int		count;
	va_list	ap;
	va_list	*args;

	va_start(ap, s);
	args = &ap;
	if (ft_strlen((char *)s) == 0)
		return (0);
	else if (!s)
		return (-1);
	count = analyse_format(s, args, fd);
	va_end(ap);
	return (count);
}

/*
int	main(void)
{
	int		i = -1;
	unsigned int	j = -1;
	unsigned int	hex = 155;
	void		*p;
    char    c = 'g';
    char    *s = NULL;
	p = 0;

	int ans = ft_printf("char: %c string: %s\nnumber: 
		%d unsigned num: %u\n pointer: %p\nhexlow: %x\nhexup : %X\n", 
							c, s, i, j, p, hex, hex);
	int	ans_0 = ft_printf(0);
	int ans_0str = ft_printf("");
	int	ans_null = ft_printf(NULL);
	
	printf("------\nCOMPARE WITH ORIGINAL PRINTF :\n");

	int compare = printf("char: %c string: %s\nnumber: 
		%d unsigned num: %u\n pointer: %p\nhexlow: %x\nhexup : %X\n",
							 c, s, i, j, p, hex, hex);
	int	compare_0 = printf(0);
	int compare_0str = printf("");
	int	compare_null = printf(NULL);
	
	printf("------\nres of ft_printf: %d\nres of print : %d\n", ans, compare);
	printf("ans_0: %d\ncompare_0 : %d\n", ans_0, compare_0);
	printf("ans_0str: %d\ncompare_0str : %d\n", ans_0str, compare_0str);
	printf("ans_null: %d\ncompare_null : %d\n", ans_null, compare_null);

	return (0);
}
*/