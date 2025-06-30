/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:03:57 by santadji          #+#    #+#             */
/*   Updated: 2023/05/16 16:52:35 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(char	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * n + 1);
	if (!new)
		return (NULL);
	while (i < n && src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	free_tab(char **tab, int i, int k)
{
	if (!tab[k])
	{	
		while (i)
		{
			if (tab[i])
				free(tab[i]);
			i--;
		}
		free(tab);
	}
	return ;
}

static int	split(char **strs, char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			strs[k] = ft_strndup(s + j, i - j);
			free_tab(strs, i, k);
			k++;
		}
	}
	strs[k] = 0;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_strs((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	if (!split(strs, (char *)s, c))
		return (NULL);
	return (strs);
}
