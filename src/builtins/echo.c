/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:56:51 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:28:57 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_flags(t_vector *cmd, size_t *index, size_t i, size_t j)
{
	int		no_newline;
	int		valid_flag;

	no_newline = 0;
	while (i < cmd->size && ((char *)ft_value(cmd, i, 0))[0] == '-')
	{
		valid_flag = 1;
		while (((char *)ft_value(cmd, i, 0))[j])
		{
			if (!ft_strchr("n", ((char *)ft_value(cmd, i, 0))[j]))
			{
				valid_flag = 0;
				break ;
			}
			j++;
		}
		if (!valid_flag)
			break ;
		no_newline = 1;
		i++;
	}
	*index = i;
	return (no_newline);
}

void	ft_builtin_echo(t_shell *shell, t_vector *cmd)
{
	size_t	i;
	int		no_newline;
	int		first_arg;

	(void)shell;
	ft_status(0);
	no_newline = ft_handle_flags(cmd, &i, 1, 1);
	first_arg = 1;
	while (i < cmd->size)
	{
		if (!first_arg)
			ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd((char *)ft_value(cmd, i, 0), STDOUT_FILENO);
		first_arg = 0;
		i++;
	}
	if (!no_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
