/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: santadji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:17:30 by santadji          #+#    #+#             */
/*   Updated: 2023/05/09 17:53:15 by santadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nbr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\r' || nbr[i] == '\n'
		|| nbr[i] == '\v' || nbr[i] == '\f')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = res * 10 + nbr[i] - '0';
		i++;
	}
	return (res * sign);
}
