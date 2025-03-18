/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:48:04 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:48:32 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_count_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_change_sub_space(char **split)
{
	int		j;
	int		m;

	m = 0;
	while (split[m])
	{
		j = 0;
		while (split[m][j])
		{
			if (split[m][j] == 0x1A)
				split[m][j] = ' ';
			j++;
		}
		m++;
	}
}

int	ft_count_chr(char *str, char ch)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (count < ft_strlen(str))
	{
		if (*str == ch)
			count++;
		str++;
	}
	return (count);
}

void	ft_replace_char_between_signal(char *str,
			char signal, char old_ch, char new_ch)
{
	char	*start;
	char	*end;
	char	*p;

	if (ft_count_chr(str, signal) < 2)
		return ;
	start = ft_strchr(str, signal);
	while (start)
	{
		end = ft_strchr(start + 1, signal);
		if (!end)
			break ;
		p = start + 1;
		while (p < end)
		{
			if (*p == old_ch)
				*p = new_ch;
			p++;
		}
		start = ft_strchr(end + 1, signal);
	}
}

char	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ');
}
