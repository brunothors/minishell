/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:16:47 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:50:47 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_status;

void	ft_handle_sigint(int signal)
{
	g_status = signal;
	if (ft_status_here(FORK, -1))
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	if (ft_status_here(HERE_DOC, -1))
	{
		ft_putstr_fd("\n", 1);
		close(STDIN_FILENO);
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		if (!ft_status_here(PROMPT, -1))
			rl_redisplay();
	}
	ft_status(130);
}

static t_status	*ft_init_status(void)
{
	static t_status	status;

	return (&status);
}

int	ft_status_here(int where, int st)
{
	t_status	*status;

	status = ft_init_status();
	if (where == 0)
	{
		if (st != -1)
			status->_heredoc = st;
		return (status->_heredoc);
	}
	else if (where == 1)
	{
		if (st == 1)
			status->_fork = st;
		return (status->_fork);
	}
	else if (where == 2)
	{
		if (st != -1)
			status->_prompt = st;
		return (status->_prompt);
	}
	else
		return (-2);
}

void	ft_sigquit(void)
{
	if (g_status == 131)
	{
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
		g_status = 0;
		ft_return_terminal(1);
	}
	ft_return_terminal(0);
}

void	ft_init_signal(void)
{
	if (signal(SIGINT, ft_handle_sigint)
		|| signal(SIGQUIT, SIG_IGN))
		exit (0);
}
