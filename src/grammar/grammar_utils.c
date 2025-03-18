/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:12:35 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 17:23:14 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pos_token_back(t_vector *phrase, int token)
{
	int	pos;

	pos = phrase->size - 1;
	while (pos >= 0)
	{
		if (ft_value_int(phrase, pos, 1) & token)
			return (pos);
		pos--;
	}
	return (-1);
}

int	ft_bracks_inside_empty(t_vector *phrase)
{
	char	*str;
	size_t	pos;

	pos = 0;
	while (pos < phrase->size)
	{
		str = ft_value(phrase, pos, 0);
		if (str[0] == '(' && ft_strlen(str) == 2)
			return (1);
		pos++;
	}
	return (0);
}

int	error(int status)
{
	if (status)
	{
		ft_putendl_fd("minishell: syntax error", STDERR_FILENO);
		ft_status(2);
		return (true);
	}
	return (false);
}
