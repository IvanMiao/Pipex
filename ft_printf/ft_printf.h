/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:23:39 by ymiao             #+#    #+#             */
/*   Updated: 2024/12/26 17:45:41 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf_fd(int fd, const char *s, ...);
int		analyse_format(const char *s, va_list *args, int fd);

void	ft_putchar(int c, int fd);
void	ft_putstr(char *s, int fd);
int		ft_strlen(char *s);
char	*ft_itoa(int n);
char	*ft_itoa_unsign(unsigned int n);
char	*ft_itoa_pointer(unsigned long p);
char	*ft_itoa_hex_low(unsigned int n);
char	*ft_itoa_hex_up(unsigned int n);

#endif
