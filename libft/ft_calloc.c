/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:01:43 by santadji          #+#    #+#             */
/*   Updated: 2023/05/27 16:37:31 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	multi;

	multi = count * size;
	if (size != 0 && multi / size != count)
		return (NULL);
	tmp = malloc(multi);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, multi);
	return (tmp);
}
