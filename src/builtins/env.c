/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:29:07 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:29:09 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env_print(t_vector *vars)
{
	unsigned long	i;
	char			*full_string;

	i = 0;
	while (i < ft_vector_size(vars))
	{
		full_string = ft_strdup(ft_value(vars, i, 3));
		if (ft_strchr(full_string, '='))
			ft_putendl_fd(full_string, STDOUT_FILENO);
		free(full_string);
		i++;
	}
}

void	ft_builtin_env(t_shell *shell, t_vector *cmd)
{
	if (cmd->size > 1)
	{
		ft_putendl_fd("env: No args accepted", STDERR_FILENO);
		ft_status(127);
	}
	else
		ft_env_print(shell->envp_dict);
}
