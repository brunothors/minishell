/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:48:35 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 17:48:42 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_size;

	p = 0;
	total_size = nmemb * size;
	if (!nmemb || !size || nmemb == total_size / size)
		p = malloc(nmemb * size);
	if (p == 0)
		return (p);
	ft_bzero(p, nmemb * size);
	return (p);
}
