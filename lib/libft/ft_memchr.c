/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:48:29 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 17:41:23 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	b;

	p = (unsigned char *) s;
	b = (unsigned char) c;
	while (n--)
	{
		if (*p != b)
			p++;
		else
			return (p);
	}
	return (0);
}
