/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:40:27 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:46:34 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_quotes(t_parse *parse, char *prompt, char *signal)
{
	signal = "";
	if (ft_strchr("\"", parse->prompt[parse->idx->i]))
	{
		prompt[parse->idx->j++] = '\"';
		signal = "\"";
	}
	else
	{
		prompt[parse->idx->j++] = '\'';
		signal = "\'";
	}
	parse->idx->i++;
	while (!ft_strchr(signal, parse->prompt[parse->idx->i]))
	{
		if (parse->prompt[parse->idx->i] == ' ')
		{
			prompt[parse->idx->j++] = 0x1A;
			parse->idx->i++;
		}
		else
			prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
	}
}

int	ft_valid_brackets_str(char *str)
{
	int	count;
	int	i;
	int	size;

	i = 0;
	count = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (ft_strchr("(", str[i]))
			count++;
		else if (ft_strchr(")", str[i]))
			count--;
		if (count < 0)
			return (1);
		i++;
	}
	if (count == 0)
		return (0);
	else
		return (1);
}

void	ft_parse_brackets(t_parse *parse, char *prompt, int count)
{
	if (parse->prompt[parse->idx->i] == '('
		|| parse->prompt[parse->idx->i] == ')')
	{
		if (ft_valid_brackets_str(&parse->prompt[parse->idx->i]))
		{
			ft_error_brackets(1);
			ft_status(2);
		}
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
		while (count != 0 && parse->prompt[parse->idx->i] != '\0')
		{
			if (parse->prompt[parse->idx->i] == ')')
				count--;
			if (parse->prompt[parse->idx->i] == '(')
				count++;
			if (parse->prompt[parse->idx->i] == ' ')
			{
				prompt[parse->idx->j++] = 0x1A;
				parse->idx->i++;
			}
			else if ((size_t)parse->idx->i < ft_strlen(parse->prompt))
				prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
		}
	}
}

int	ft_aux_parse_char(char *ch, t_parse *parse, char *prompt)
{
	if (ft_strncmp(ch, &parse->prompt[parse->idx->i], 2) == 0)
	{
		prompt[parse->idx->j++] = ' ';
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i++];
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i];
		prompt[parse->idx->j] = ' ';
		return (1);
	}
	return (0);
}

int	ft_parse_char(t_parse *parse, char *prompt)
{
	if (ft_aux_parse_char("<<", parse, prompt))
		return (1);
	else if (ft_aux_parse_char(">>", parse, prompt))
		return (1);
	else if (ft_aux_parse_char("&&", parse, prompt))
		return (1);
	else if (ft_aux_parse_char("||", parse, prompt))
		return (1);
	else if (ft_strchr("><|()", parse->prompt[parse->idx->i]))
	{
		prompt[parse->idx->j++] = ' ';
		prompt[parse->idx->j++] = parse->prompt[parse->idx->i];
		prompt[parse->idx->j] = ' ';
		return (1);
	}
	return (0);
}
