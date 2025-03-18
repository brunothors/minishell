/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_macros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:52:57 by bnespoli          #+#    #+#             */
/*   Updated: 2025/01/16 16:49:02 by bnespoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_term_by_signal(int status)
{
	return (((signed char)((status & 0x7f) + 1) >> 1) > 0);
}

int	ft_term_normaly(int status)
{
	return (ft_term_by_signal(status) == 0);
}

int	ft_exit_status(int status)
{
	return ((status >> 8) & 0xFF);
}

int	ft_term_signal(int status)
{
	return (status & 0x7F);
}

int	ft_get_return_value(int status)
{
	if (ft_term_by_signal(status))
		return (ft_term_signal(status) + 128);
	return (ft_exit_status(status));
}
