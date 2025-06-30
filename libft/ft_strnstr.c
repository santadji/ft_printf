/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:10:03 by santadji          #+#    #+#             */
/*   Updated: 2023/05/11 17:51:48 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!str || !to_find) && len == 0)
		return (NULL);
	if (to_find[i] == '\0')
		return ((char *)str + i);
	while (str[i] && i < len)
	{
		j = 0;
		while (to_find[j] && str[i + j] == to_find[j] && i + j < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
