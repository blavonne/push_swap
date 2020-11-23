/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int			is_flag(char *str)
{
	if (ft_strlen(str) == 2 && str[0] == '-' && ft_isalpha(str[1]))
		return (1);
	return (0);
}

static void			add_flag(char *str, int *flag)
{
	if (ft_strequ(str, "-v"))
		(*flag) |= DEBUG;
	else if (ft_strequ(str, "-r"))
		(*flag) |= TO_FILE;
	else if (ft_strequ(str, "-w"))
		(*flag) |= FROM_FILE;
}
*/
/*
int			flag_manager(int argc, char **argv, t_info *info)
{
	int		i;

	while (i < argc)
	{
		if (is_flag(argv[i]))
			add_flag(argv[i], &info->flag);
		if (info->flag & TO_FILE && i + 1 < argc)
		{
			i++;
			if (!add_file_w(info, argv[i]))

		}
	}
}
*/