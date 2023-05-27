/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:05:51 by santadji          #+#    #+#             */
/*   Updated: 2023/05/27 18:57:07 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_type(va_list *args, char *str, int i, int *ret);
void	ft_putchar_fd_printf(char c, int fd, int *ret);

void	ft_printmod(va_list *args, char *str, int *i, int *ret)
{
	(*i)++;
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' || str[*i] == 'd'
		|| str[*i] == 'i' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'x'
		|| str[*i] == 'X' || str[*i] == '%')
		ft_type(args, str, *i, ret);
	else
	{
		ft_putchar_fd_printf('%', 1, ret);
		ft_putchar_fd_printf(str[*i], 1, ret);
	}
}

int	ft_printf(const char *format, ...)
{
	char		*str;
	int			i;
	int			ret;
	va_list		args;

	i = 0;
	ret = 0;
	va_start(args, format);
	str = (char *)format;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_printmod(&args, str, &i, &ret);
		else
			ft_putchar_fd_printf(str[i], 1, &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
/*
int	main()
{
	printf("TEST CHAR\n\n");
	char c = 'A';
	int	retc0 = ft_printf("%c", c);
	printf("\n");
	printf("ret1 = %d\n\n\n", retc0);

	printf("TEST STRING\n\n");
	char *s = "abc";
	int	rets0 = ft_printf("%s", s);
	printf("\n");
	printf("ret1 = %d\n\n\n", rets0);

	printf("TEST INTEGER\n\n");
	int	d = 45;
	int d1 = -2147483648;
	int d2 = -45;
	int retd0 = ft_printf("%d", d);
	printf("\n");
	int	retd1 = ft_printf("%d", d1);
	printf("\n");
	int	retd2 = ft_printf("%d", d2);
	printf("\nret1 = %d\nret2 = %d\nret3 = %d\n\n", retd0, retd1, retd2);
 
	printf("TEST DECIMAL INT\n\n");
	int	i = 45;
	int i1 = -2147483648;
	int i2 = -45;
	int reti0 = ft_printf("%i", i);
	printf("\n");
	int	reti1 = ft_printf("%i", i1);
	printf("\n");
	int	reti2 = ft_printf("%i", i2);
	printf("\nret1 = %i\nret2 = %i\nret3 = %i\n\n\n", reti0, reti1, reti2);

	printf("TEST UNSIGNED INT\n\n");
	unsigned int	u = 45;
	unsigned int u1 = -2147483647;
	unsigned int u2 = -45;
	int retu0 = ft_printf("%u", u);
	printf("\n");
	int	retu1 = ft_printf("%u", u1);
	printf("\n");
	int	retu2 = ft_printf("%u", u2);
	printf("\nret1 = %u\nret2 = %u\nret3 = %u\n\n\n", retu0, retu1, retu2);

	printf("TEST HEXA MIN\n\n");
	int	x = 45;
	int x1 = 2147483648;
	int x2 = 255;
	int retx0 = ft_printf("%x", x);
	printf("\n");
	int	retx1 = ft_printf("%x", x1);
	printf("\n");
	int	retx2 = ft_printf("%x", x2);
	printf("\nret1 = %x\nret2 = %x\nret3 = %x\n\n\n", retx0, retx1, retx2);
	
	printf("TEST HEXA MAJ\n\n");
	int	X = 45;
	int X1 = -2147483648;
	int X2 = 255;
	int retX0 = ft_printf("%X", X);
	printf("\n");
	int	retX1 = ft_printf("%X", X1);
	printf("\n");
	int	retX2 = ft_printf("%X", X2);
	printf("\nret1 = %X\nret2 = %X\nret3 = %X\n\n\n", retX0, retX1, retX2);

	printf("TEST ADRESS\n\n");
//	void *p = 45;
//	void *p1 = -2147483648;
//	void *p2 = 45;
	ft_printf("%p\n", -1);
	ft_printf("%p\n", 15);
	ft_printf("%p\n", 17);
//	printf("\nret1 = %p\nret2 = %p\nret3 = %p\n\n\n", retp0, retp1, retp2);
}*/
