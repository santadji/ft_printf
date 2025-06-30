/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:39:04 by santadji          #+#    #+#             */
/*   Updated: 2023/05/22 10:38:48 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse(char *str)
{
	int		start;
	int		end;
	char	*s;

	start = 0;
	end = ft_strlen(str) -1;
	s = malloc(sizeof(char) * (end + 2));
	if (!s)
		return (NULL);
	while (end >= 0)
	{
		s[start] = str[end];
		end--;
		start++;
	}
	s[start] = '\0';
	return (s);
}

static char	*zero_malloc(void)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char		s[12];
	long int	nb;
	int			i;
	int			sign;

	sign = 1;
	i = 0;
	nb = (long int)n;
	if (nb == 0)
		return (zero_malloc());
	if (nb < 0)
	{
		nb = -nb;
		sign = -1;
	}
	while (nb)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	if (sign == -1)
		s[i++] = '-';
	s[i] = '\0';
	return (reverse(s));
}
