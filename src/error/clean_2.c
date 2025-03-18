/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:14 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:32:52 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clear_ast(t_node	*root)
{
	if (root)
	{
		if (root->left)
			ft_clear_ast(root->left);
		if (root->right)
			ft_clear_ast(root->right);
		ft_inside_ast(root);
		if (root)
			free(root);
	}
}

void	ft_clear_vector(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		free(ft_vector_at(vector, i));
		i++;
	}
	ft_vector_free(vector);
}

void	ft_clean_vector(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->size)
	{
		free(vector->values[i]);
		i++;
	}
	free(vector->values);
	free(vector);
}
