/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				is_flag(char *str)
{
	if (ft_strlen(str) == 2 && str[0] == '-' && ft_isalpha(str[1]))
		return (1);
	return (0);
}

void			add_flag(char *str, int *flag)
{
	if (ft_strequ(str, "-v"))
		(*flag) |= DEBUG;
	else if (ft_strequ(str, "-f"))
		(*flag) |= TO_FILE;
	else if (ft_strequ(str, "-c"))
		(*flag) |= COLOR;
}

int				is_file(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 4)
	{
		while (str[i])
			i++;
		if (str[i - 1] == 't' && str[i - 2] == 'x' && str[i - 3] == 't' &&\
			str[i - 4] == '.')
			return (1);
	}
	return (0);
}

void			add_file(t_info *info, char *str)
{
	if (!info->to_file)
		info->to_file = str;
}
