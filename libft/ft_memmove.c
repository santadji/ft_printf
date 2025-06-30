/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:38:03 by santadji          #+#    #+#             */
/*   Updated: 2023/05/09 17:56:53 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	int		i;
	char	*d;
	char	*s;

	i = len - 1;
	d = (char *)dst;
	s = (char *)src;
	if (d > s && s + len > d)
	{
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
