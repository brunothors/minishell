/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:11:48 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 20:06:40 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_check_limits(int signal, unsigned long long num, bool *error)
{
	if ((signal == 1 && num > LONG_MAX) || (signal == -1 && num
			> -(unsigned long)LONG_MIN))
		*error = true;
	return (*error);
}

static int	ft_is_number(char *str, bool *error)
{
	size_t	i;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '\0')
		*error = true;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		*error = true;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_space(str[i]))
			*error = true;
		i++;
	}
	i = (unsigned char)ft_atoll_check(str, error);
	return (i);
}

void	ft_clear2(t_shell *shell)
{
	ft_close_open_fds();
	ft_clear_ast(shell->root);
	ft_free_matrix(shell->parse->prompt_splitted);
	free(shell->parse);
	ft_free_shell(shell);
	rl_clear_history();
}

void	ft_numeric_argument_required(t_shell *shell)
{
	ft_putendl_fd("exit: numeric argument required", STDERR_FILENO);
	ft_status(2);
	ft_clear2(shell);
	exit(2);
}

void	ft_builtin_exit(t_shell *shell, t_vector *cmd)
{
	unsigned char	ft_exit_status;
	bool			error;

	if (cmd == NULL || cmd->size == 1)
	{
		ft_clear2(shell);
		exit(0);
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	error = false;
	if (cmd->size > 1)
	{
		ft_exit_status = ft_is_number(ft_value(cmd, 1, 0), &error);
		if (error)
			ft_numeric_argument_required(shell);
		else if (cmd->size > 2)
		{
			ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			ft_status(1);
			return ;
		}
	}
	ft_exit_status = ft_is_number(ft_value(cmd, 1, 0), &error);
	ft_clear2(shell);
	exit(ft_exit_status);
}
