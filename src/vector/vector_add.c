/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:31:44 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:56:53 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_vector_push_back(t_vector *vector, void *value)
{
	unsigned long	new_capacity;

	if (vector == NULL)
		return ;
	if (vector->size >= vector->capacity)
	{
		new_capacity = vector->capacity + (vector->capacity >> 1);
		if (!ft_vector_resize(vector, new_capacity))
			return ;
	}
	vector->values[vector->size] = value;
	vector->size++;
}

unsigned long	ft_vector_insert(t_vector *vector, unsigned long position,
		void *value)
{
	unsigned long	new_capacity;
	unsigned long	i;

	if (vector == NULL)
		return (0);
	if (position > vector->size)
		return (0);
	if (vector->size >= vector->capacity)
	{
		new_capacity = vector->capacity + (vector->capacity >> 1);
		if (!ft_vector_resize(vector, new_capacity))
			return (0);
	}
	i = vector->size;
	while (i > position)
	{
		vector->values[i] = vector->values[i - 1];
		--i;
	}
	vector->values[position] = value;
	vector->size++;
	return (position);
}
