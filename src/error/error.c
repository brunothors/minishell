/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:45:45 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:33:06 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

void	ft_error(char *cmd, char *flag, char *msg, int status)
{
	struct stat	path_stat;

	path_stat = (struct stat){0};
	stat((const char *) cmd, &path_stat);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (flag)
	{
		ft_putstr_fd(flag, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if ((ft_strchr("./", cmd[0]) || cmd[ft_strlen(cmd) - 1] == '/'
			|| cmd[0] == '/') && status != ENOENT
		&& path_stat.st_mode & S_IFDIR)
		ft_putstr_fd("Is a directory\n", STDERR_FILENO);
	else
		ft_putendl_fd(msg, STDERR_FILENO);
	if (status == EACCES)
		ft_status(126);
	else if (status == ENOENT)
		ft_status(127);
	else
		ft_status(status);
}

void	ft_close_open_fds(void)
{
	struct dirent	*file;
	DIR				*root;
	int				fd;

	root = opendir("/proc/self/fd/");
	while (1)
	{
		file = readdir(root);
		if (!file)
			break ;
		fd = ft_atoi(file->d_name);
		if (fd > -1 && fd < 1024)
			close(ft_atoi(file->d_name));
	}
	closedir(root);
}

void	ft_clear(t_shell *shell)
{
	ft_close_open_fds();
	shell->parse->phrase_grammar = NULL;
	shell->parse->phrase = NULL;
	ft_free_matrix(shell->parse->prompt_splitted);
	ft_clear_ast(shell->root);
	free(shell->parse);
	ft_free_shell(shell);
}

void	ft_clear_pipe(t_shell *shell)
{
	if (shell->str)
		free(shell->str);
	ft_free_matrix(shell->parse->prompt_splitted);
	free(shell->parse);
	ft_clear_ast(shell->root);
	ft_clear_brackets(shell);
}
