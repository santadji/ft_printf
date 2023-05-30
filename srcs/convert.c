/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:01:48 by santadji          #+#    #+#             */
/*   Updated: 2023/05/28 16:48:01 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*check_ad(unsigned long int n, char *base)
{
	if (n == 0)
		return (ft_strdup("(nil)"));
	else
		return (ft_itoa_base(n, base));
}

void	itoa_free(va_list *args, int *ret, char c)
{
	char	*s1;
	char	*str;

	str = NULL;
	if (c == 'x')
	{
		str = ft_itoa_base(va_arg(*args, unsigned int), "0123456789abcdef");
		ft_putstr_fd_printf(str, 1, ret);
	}
	if (c == 'X')
	{
		str = ft_itoa_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
		ft_putstr_fd_printf(str, 1, ret);
	}
	if (c == 'p')
	{
		s1 = check_ad(va_arg(*args, unsigned long), "0123456789abcdef");
		str = ft_strjoin("0x", s1);
		if (ft_strncmp("(nil)", s1, 5) != 0)
			ft_putstr_fd_printf(str, 1, ret);
		else
			ft_putstr_fd_printf(s1, 1, ret);
		free(s1);
	}
	free(str);
}
