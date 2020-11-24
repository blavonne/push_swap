/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_number(char *str, long long *number)
{
	int				sign;
	int				i;

	i = 0;
	(*number) = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			(*number) = (*number) * 10 + str[i] - '0';
		i++;
	}
	(*number) *= sign;
	if ((*number) < INT_MIN || (*number) > INT_MAX)
		return (0);
	return (1);
}

void				read_argv(int argc, char **argv, t_info *info)
{
	int				i;
	long long int	number;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0)
			clean_and_exit(info, 'm');
		if (ft_isnumber(argv[i]))
		{
			if (ft_strlen(argv[i]) > 11 || !get_number(argv[i], &number))
				clean_and_exit(info, 'm');
			push_in_stack(&info->a, (int)number);
		}
		else if (is_flag(argv[i]))
			add_flag(argv[i], &info->flag);
		else if (info->flag & TO_FILE && is_file(argv[i]))
			add_file(info, argv[i]);
		else if (!(try_to_split(argv[i], info)))
			clean_and_exit(info, 'm');
		i++;
	}
}
