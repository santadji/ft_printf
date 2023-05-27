/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:01:48 by santadji          #+#    #+#             */
/*   Updated: 2023/05/27 17:11:15 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	reverse(char *str)
{
	int	len;
	int	i;
	int	j;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char	*ft_itoa_base(int n, char *base)
{
	int		i;
	int		len;
	int		tmp;
	char	*res;

	if (n == 0)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	len = 0;
	tmp = n;
	while (tmp != 0)
	{
		len++;
		tmp /= ft_strlen(base);
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		tmp = n % ft_strlen(base);
		if (tmp > 9)
			res[i] = (tmp - 10) + 'A';
		else
			res[i] = tmp + '0';
		n /= ft_strlen(base);
		i++;
	}
	res[i] = '\0';
	reverse(res);
	return (res);
}
