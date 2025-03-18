/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:14:05 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:43:05 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern volatile sig_atomic_t	g_status;

long	ft_count(void)
{
	static long	count;

	return (count++);
}

void	ft_end_heredoc(int infile, char *gnl)
{
	if (g_status != SIGINT && gnl == NULL)
	{
		ft_putstr_fd("minishell: warning: ", 2);
		ft_putstr_fd("here-document delimited by end-of-file\n", 2);
	}
	close(infile);
}

char	*ft_limiter(t_node *root, t_shell *shell)
{
	char	*limiter;
	char	*temp;

	limiter = ft_strdup(root->str);
	if (ft_count_chr(limiter, '\"') != 0
		|| ft_count_chr(limiter, '\'') != 0)
	{
		temp = limiter;
		limiter = ft_eliminate_signal(temp, shell);
		free(temp);
	}
	return (limiter);
}
