/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:52:30 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 17:46:08 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static size_t	count_wordlen(char const *s, char c);
static char		**mem_cleanup(char **lst);

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	wordlen;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	lst = (char **)ft_calloc(count_words(s, c) + 1, sizeof(char *));
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			wordlen = count_wordlen(s, c);
			lst[i] = ft_substr(s, 0, wordlen);
			if (!lst[i])
				return (mem_cleanup(lst));
			i++;
			s += wordlen;
		}
	}
	lst[i] = NULL;
	return (lst);
}

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	count_wordlen(char const *s, char c)
{
	size_t	wordlen;

	if (!ft_strchr(s, c))
		wordlen = ft_strlen(s);
	else
		wordlen = ft_strchr(s, c) - s;
	return (wordlen);
}

static char	**mem_cleanup(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
	return (NULL);
}
