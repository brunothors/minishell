/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:37:41 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:30:10 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_builtin_pwd(t_shell *shell, t_vector *cmd)
{
	char	cwd[PATH_MAX];

	(void)cmd;
	(void)shell;
	ft_status(0);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		ft_putendl_fd(cwd, STDOUT_FILENO);
	else
	{
		ft_putendl_fd("Error getting current directory", STDERR_FILENO);
		ft_status(1);
	}
}
