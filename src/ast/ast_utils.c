/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:27:24 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:25:12 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_eliminate_ch_corner(char *str)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	i = 0;
	while (i < size)
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i - 1] = '\0';
	str[i - 2] = '\0';
}

void	ft_inside_ast(t_node *root)
{
	free(root->str);
	free(root->str_not_expanded);
	ft_freephrase(root->phrase);
}
