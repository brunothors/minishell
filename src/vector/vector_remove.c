/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:29:36 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:58:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_vector_pop_back(t_vector *vector)
{
	if (vector == NULL)
		return ;
	if (ft_vector_empty(vector))
		return ;
	ft_vector_erase(vector, vector->size - 1);
}

void	ft_vector_erase(t_vector *vector, unsigned long position)
{
	unsigned long	i;

	if (vector == NULL)
		return ;
	if (position >= vector->size)
		return ;
	i = position;
	while (i < vector->size - 1)
	{
		vector->values[i] = vector->values[i + 1];
		++i;
	}
	vector->size--;
}
