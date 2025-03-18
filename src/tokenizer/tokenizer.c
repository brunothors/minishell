/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:55:31 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:56:15 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_token(char *str)
{
	int			n;
	const char	*tokens[10] = {"<", ">", "<<", ">>",
		"||", "&&", "|", "(", ")", 0};

	n = 0;
	while (tokens[n])
	{
		if (ft_strlen(str) <= 2 && !ft_strncmp(str, tokens[n], 3))
			return (1 << n);
		n++;
	}
	return (0);
}
