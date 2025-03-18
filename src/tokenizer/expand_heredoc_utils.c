/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:23:57 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:15 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	ft_signal(t_vector *vector, size_t *i, char signal)
{
	if (ft_strchr("\'\"", ((char *)ft_vector_at(vector, *i))[0]))
	{
		if (ft_strchr((char *)ft_vector_at(vector, (*i)++), '\"'))
			signal = '\"';
		else
			signal = '\'';
	}
	else
		signal = '\0';
	return (signal);
}
