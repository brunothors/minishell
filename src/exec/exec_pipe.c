/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:45:29 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:34:24 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_dup_aux(int *fd, int side)
{
	if (side == LEFT)
		dup2(fd[1], STDOUT_FILENO);
	if (side == RIGHT)
		dup2(fd[0], STDIN_FILENO);
}

static void	ft_execution_side(t_node *root, t_shell *shell, int side)
{
	if (side == LEFT)
		ft_execution(root->left, shell);
	if (side == RIGHT)
		ft_execution(root->right, shell);
}

static void	ft_pipe_aux(t_node *root, t_shell *shell, int *fd, int side)
{
	ft_status_here(FORK, 1);
	rl_clear_history();
	ft_dup_aux(fd, side);
	ft_close_fd(fd);
	ft_execution_side(root, shell, side);
	ft_clear_pipe(shell);
	exit (ft_status(-1));
}

void	ft_pipe(t_node *root, t_shell *shell)
{
	int		fd[2];
	pid_t	pid[2];

	if (pipe(fd) < 0)
		exit (0);
	pid[0] = fork();
	if (pid[0] == 0)
		ft_pipe_aux(root, shell, fd, LEFT);
	pid[1] = fork();
	if (pid[1] == 0)
		ft_pipe_aux(root, shell, fd, RIGHT);
	close(fd[0]);
	close(fd[1]);
	ft_pid_status_without_flobal(pid[0]);
	ft_pid_status(pid[1]);
}
