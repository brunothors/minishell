/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:50:37 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:35:08 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_status(int st)
{
	static int	status;

	if (st != -1)
		status = st;
	return (status);
}

void	ft_close_fd(int *fd)
{
	if (!fd)
		return ;
	if (fd[0] > -1)
		close(fd[0]);
	if (fd[1] > -1)
		close(fd[1]);
}

void	ft_change_fds(int fd, int new)
{
	if (fd != -1)
	{
		dup2(fd, new);
		close(fd);
	}
}

void	ft_pid_status(pid_t pid)
{
	int	status;

	status = ft_status(-1);
	waitpid(pid, &status, WUNTRACED);
	status = ft_get_return_value(status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (status == 139)
		status = 1;
	ft_status(status);
}

void	ft_pid_status_without_flobal(pid_t pid)
{
	int	status;

	status = ft_status(-1);
	waitpid(pid, &status, WUNTRACED);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (status == 139)
		status = 1;
	ft_status(status);
}
