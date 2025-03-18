/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:31:52 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:32:00 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_cmd(char *str)
{
	if (str && ft_strncmp(str, "/", 1) == 0)
		if (access(str, F_OK | X_OK) == 0)
			return (1);
	return (0);
}

char	*ft_get_pathname(char **matrix, char *str)
{
	char	*bar;
	char	*pathname;
	int		i;

	i = 0;
	if (ft_strlen(str) == 0 || matrix == NULL)
		return (ft_strdup(""));
	if (ft_is_cmd(str))
		return (ft_strdup(str));
	while (matrix[i] != NULL)
	{
		bar = ft_strjoin(matrix[i], "/");
		pathname = ft_strjoin(bar, str);
		if (pathname && access(pathname, F_OK | X_OK) == 0)
			return (free(bar), pathname);
		else
		{
			free(bar);
			free (pathname);
		}
		i++;
	}
	return (ft_strdup(str));
}
