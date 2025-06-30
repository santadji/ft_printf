/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:02 by santadji          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:46 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
