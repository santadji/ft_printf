/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:09:20 by santadji          #+#    #+#             */
/*   Updated: 2023/05/22 15:44:17 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar_fd_printf(char c, int fd, int *ret)
{
	write(fd, &c, 1);
	(*ret)++;
}

void	ft_putstr_fd_printf(char *s, int fd, int *ret)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd_printf(s[i], fd, ret);
		i++;
	}
}

void	ft_putnbr_fd_printf(int n, int fd, int *ret)
{
	if (n == -2147483648)
		ft_putstr_fd_printf("-2147483648", fd, ret);
	else if (n < 0)
	{
		ft_putchar_fd_printf('-', fd, ret);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd_printf(n / 10, fd, ret);
		ft_putnbr_fd_printf(n % 10, fd, ret);
	}
	if (n < 10)
		ft_putchar_fd_printf(n + '0', fd, ret);
}

void	ft_putnbr_fd_unsigned_printf(unsigned int n, int fd, int *ret)
{
	if (n < 10)
		ft_putchar_fd_printf(n + '0', fd, ret);
	else if (n > 9)
	{
		ft_putnbr_fd_unsigned_printf(n / 10, fd, ret);
		ft_putchar_fd_printf(n % 10 + '0', fd, ret);
	}
}

void	ft_type(va_list *args, char *str, int i, int *ret)
{
	if (str[i] == 'c')
		ft_putchar_fd_printf(va_arg(*args, int), 1, ret);
	if (str[i] == 's')
		ft_putstr_fd_printf(va_arg(*args, char *), 1, ret);
	if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr_fd_printf(va_arg(*args, int), 1, ret);
	if (str[i] == 'u')
		ft_putnbr_fd_unsigned_printf(va_arg(*args, unsigned int), 1, ret);
/*	if (str[i] == 'x')
		ft_itoa_base(va_args(args, unsigned int), "0123456789abcdef");
	if (str[i] == 'X')
		ft_itoa_base(va_args(args, unsigned int), "0123456789ABCDEF");
	if (str[i] == 'p')
		ft_putstr_fd("0x", 1);
		ft_itoa_base(va_args(args, void), "023456789abcdef");
*/}


