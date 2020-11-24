/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_to_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:33 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:30:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ==========TRY_SA==========
** This func tries to do sa and if stack a is slice after that
** then it returns 1 otherwise it rolls back sa and returns 0
*/

int				try_sa(t_info *info)
{
	if (info->a && info->a->next && info->a->next->next)
	{
		run_command("sa", info);
		if (is_slice(info->a))
		{
			if (!push_in_vector(&(info)->cmd_c, SA, sizeof(char)))
				clean_and_exit(info, 'm');
			return (1);
		}
		else
			run_command("sa", info);
	}
	return (0);
}

void			to_b_rrb(t_info *info, int middle)
{
	int		value;

	while (info->a && !is_slice((info->a)))
	{
		run_command("rra", info);
		value = info->a->value;
		if (value < middle)
		{
			if (!push_in_vector(&info->cmd_c, RRA, sizeof(char)))
				clean_and_exit(info, 'm');
			run_command("pb", info);
			if (!push_in_vector(&info->cmd_c, PB, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		else
		{
			run_command("ra", info);
			break ;
		}
		try_sa(info);
	}
}

void			to_b_rb(t_info *info, int middle)
{
	while (info->a && !is_slice((info->a)))
	{
		if (info->a->value < middle)
		{
			run_command("pb", info);
			if (!push_in_vector(&info->cmd_c, PB, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		else
			break ;
		try_sa(info);
	}
}

void			all_to_b(t_info *info)
{
	int				middle_val;

	while (info->a && info->a->next && info->a->next->next &&\
	!(is_slice(info->a)))
	{
		middle_val = get_middle(info);
		try_sa(info);
		while (check_mid(info->a, middle_val) && !(is_slice((info->a))))
		{
			try_sa(info);
			to_b_rb(info, middle_val);
			to_b_rrb(info, middle_val);
			do_rotate(info, middle_val);
		}
	}
}
