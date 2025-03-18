/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:51:45 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 17:43:04 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decimal(int n)
{
	long	nb;
	int		sign;
	int		decimal;

	decimal = 0;
	sign = 0;
	nb = (long) n;
	if (nb < 0)
	{
		nb = -nb;
		sign++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		decimal++;
	}
	if (sign == 1)
		decimal++;
	if (decimal == 0)
		return (1);
	return (decimal);
}

static void	*ft_recursive_itoa(long n, char *result, int *i)
{
	if (n < 0)
	{
		result[(*i)++] = '-';
		n = -n;
	}
	if (n >= 10)
		ft_recursive_itoa(n / 10, result, i);
	result[(*i)++] = (n % 10) + 48;
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	char	*itoa;
	int		i;

	i = 0;
	n = (long) n;
	result = ft_calloc(ft_decimal(n) + 1, sizeof(char));
	if (result == 0)
		return (0);
	itoa = ft_recursive_itoa(n, result, &i);
	i = ft_decimal(n);
	*(itoa + i) = '\0';
	return (itoa);
}
