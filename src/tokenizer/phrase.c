/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrase.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:55:13 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:55:19 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vector	*ft_construct_phrase(char **split, t_shell *shell)
{
	t_vector	*phrase;
	int			i;
	int			*token;
	t_vector	*word;

	(void)shell;
	phrase = ft_vector_create();
	if (!phrase)
		return (NULL);
	i = 0;
	while (split[i])
	{
		word = ft_vector_create();
		ft_vector_push_back(word, ft_strdup(split[i]));
		token = malloc(sizeof(int));
		*token = ft_set_token(split[i]);
		ft_vector_push_back(word, token);
		ft_vector_push_back(word, ft_strdup(split[i]));
		ft_vector_push_back(phrase, word);
		i++;
	}
	return (phrase);
}
