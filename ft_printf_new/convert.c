/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:01:48 by santadji          #+#    #+#             */
/*   Updated: 2023/05/27 19:25:32 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char *str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	char	*str;
	char	*s1;
	char	*s2;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	if (n >= (unsigned int)ft_strlen(base))
	{
		s1 = ft_itoa_base(n / ft_strlen(base), base);
		s2 = ft_itoa_base(n % ft_strlen(base), base);
		free(str);
		str = ft_strjoin(s1, s2);
		free(s1);
		free(s2);
	}
	else if (n < (unsigned int)ft_strlen(base))
	{
		str[0] = base[n];
		str[1] = '\0';
	}
	return (str);
}
/*
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
			res[i] = (tmp - 10) + '0';
		else
			res[i] = tmp + '0';
		n /= ft_strlen(base);
		i++;
	}
	res[i] = '\0';
	reverse(res);
	return (res);
}*/
