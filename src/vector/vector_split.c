/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:40:47 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:59:15 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vector	*ft_vector_slice_right(t_vector *vector, unsigned long pos)
{
	unsigned long	i;
	int				j;
	t_vector		*sliced;

	if (vector == NULL || pos >= vector->size)
		return ((t_vector *)0);
	sliced = ft_vector_create();
	i = vector->size;
	pos++;
	j = 0;
	while (pos < i)
	{
		ft_vector_push_back(sliced, vector->values[pos]);
		pos++;
		j++;
	}
	j--;
	while (j >= 0)
	{
		ft_vector_pop_back(vector);
		j--;
	}
	return (sliced);
}
