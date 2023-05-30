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

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
void ft_putstr_fd_printf(char *str, int fd, int *ret);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;

	len = ft_strlen((char *)src) + 1;
	new = malloc(len * sizeof(char));
	if (!new)
		return (NULL);
	ft_strcpy(new, (char *)src);
	return (new);
}

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

char	*ft_itoa_base(unsigned long int n, char *base)
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
