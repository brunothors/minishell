/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:23:28 by vcarrara          #+#    #+#             */
/*   Updated: 2025/01/16 17:20:23 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_status = 0;

void	ft_return_terminal(int ret)
{
	static struct termios	term;

	if (!ret)
		tcgetattr(STDIN_FILENO, &term);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	main(void)
{
	t_shell		*shell;
	extern char	**environ;

	shell = malloc(sizeof(t_shell));
	if (shell == NULL)
		return (EXIT_FAILURE);
	shell->envp = environ;
	shell->str = 0;
	ft_init_signal();
	ft_envp(shell);
	ft_status(0);
	ft_return_terminal(0);
	while (true)
	{
		ft_sigquit();
		ft_to_execute(ft_readline(shell), shell);
	}
	return (0);
}
