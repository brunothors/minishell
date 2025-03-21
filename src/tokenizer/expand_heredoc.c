/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:55:07 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:51:36 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_parse_expand_heredoc_aux(char **str, t_shell *shell,
		t_vector *vector)
{
	size_t		i;
	int			not_expanded;

	i = 0;
	not_expanded = 0;
	while (i < vector->size)
	{
		str[2] = (char *)ft_vector_at(vector, i);
		str[3] = ft_expand(str[2], shell);
		if (ft_strncmp(str[3], "0x1A", 4) != 0)
		{
			str[0] = ft_strjoin(str[1], str[3]);
			if (ft_strlen(str[1]) != 0)
				free(str[1]);
			str[1] = str[0];
			not_expanded++;
		}
		i++;
	}
	ft_clean_vector(vector);
	if (not_expanded == 0)
		return (ft_strdup("0x1A"));
	return (str[0]);
}

char	*ft_parse_expand_heredoc(char *s, t_shell *shell)
{
	t_vector	*vector;
	char		*str[4];
	char		*final_str;

	str[0] = "";
	str[1] = "";
	str[2] = "";
	str[3] = "";
	vector = ft_vector_create();
	ft_split_expand(s, vector);
	final_str = ft_parse_expand_heredoc_aux(str, shell, vector);
	if (ft_strncmp(final_str, "0x1A", 4) == 0)
	{
		free(final_str);
		return (ft_strdup(""));
	}
	return (final_str);
}

void	ft_final_signal(char **str)
{
	str[2] = ft_strdup(str[3]);
	str[0] = ft_strjoin(str[1], str[2]);
	free(str[2]);
	if (ft_strlen(str[1]) != 0)
		free(str[1]);
	str[1] = str[0];
}

char	*ft_eliminate_signal_aux(char **str, t_shell *shell,
		t_vector *vector)
{
	unsigned long int	i;
	char				signal;

	i = 0;
	signal = '\0';
	(void )shell;
	while (i < vector->size)
	{
		signal = ft_signal(vector, &i, signal);
		str[3] = (char *)ft_vector_at(vector, i);
		while ((i < vector->size) && (signal != '\0' || !ft_strchr("\'\"",
					str[3][0])) && (str[3] == NULL || signal != str[3][0]))
		{
			if (signal == '\'')
				ft_final_signal(str);
			else if (ft_strncmp(str[3], "0x1A", 4) != 0)
				ft_final_signal(str);
			i++;
			str[3] = (char *)ft_vector_at(vector, i);
		}
		signal = '\0';
	}
	ft_clean_vector(vector);
	return (str[0]);
}

char	*ft_eliminate_signal(char *s, t_shell *shell)
{
	t_vector	*vector;
	char		*final_str;
	char		*str[4];

	str[0] = "";
	str[1] = "";
	str[2] = "";
	str[3] = "";
	vector = ft_vector_create();
	ft_split_expand(s, vector);
	final_str = ft_eliminate_signal_aux(str, shell, vector);
	return (final_str);
}
