/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_inputs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:45:49 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 20:00:57 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_status;

int	ft_prompt_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_to_execute_aux(t_shell *shell)
{
	if (!ft_open_heredoc(shell->root, shell))
	{
		ft_clear_ast(shell->root);
		ft_freephrase(shell->parse->phrase_grammar);
		return ;
	}
	if (ft_grammar_rules(shell->parse->phrase_grammar))
	{
		ft_freephrase(shell->parse->phrase_grammar);
		ft_execution(shell->root, shell);
	}
	else
		if (shell->parse->phrase_grammar)
			ft_freephrase(shell->parse->phrase_grammar);
	ft_clear_ast(shell->root);
}

void	ft_to_execute(char *str, t_shell *shell)
{
	if (!str || ft_strlen(str) == 0 || ft_prompt_only_space(str))
		return ;
	shell->parse = malloc(sizeof(t_parse));
	shell->parse->prompt = str;
	shell->parse->prompt_splitted = ft_parser(shell->parse);
	shell->parse->phrase = \
		ft_construct_phrase(shell->parse->prompt_splitted, shell);
	shell->parse->phrase_grammar = \
		ft_construct_phrase(shell->parse->prompt_splitted, shell);
	ft_order_redall(shell->parse->phrase);
	shell->root = ft_ast(shell->parse->phrase);
	if (shell->root)
		ft_to_execute_aux(shell);
	ft_free_matrix(shell->parse->prompt_splitted);
	free(shell->parse);
	return ;
}

char	*ft_readline(t_shell *shell)
{
	char	*prompt;

	ft_status_here(PROMPT, 0);
	prompt = readline("minishell>$ ");
	ft_status_here(PROMPT, 1);
	if (!prompt)
	{
		printf("exit\n");
		ft_free_shell(shell);
		rl_clear_history();
		exit(0);
	}
	if (!ft_prompt_only_space(prompt))
		add_history(prompt);
	return (prompt);
}
