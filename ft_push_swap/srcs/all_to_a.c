/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_to_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:36:44 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:38:45 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_rr(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->place.rr)
	{
		if ((info->place.way_to_b == 't' && info->place.way_to_a == 't'))
		{
			run_command("rr", info);
			if (!push_in_vector(&info->cmd_c, RR, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		else if (info->place.way_to_b == 'b' &&\
		info->place.way_to_a == 'b')
		{
			run_command("rrr", info);
			if (!push_in_vector(&info->cmd_c, RRR, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		i++;
	}
}

void		to_top_b(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->place.steps_to_b)
	{
		if (info->place.way_to_b == 't')
		{
			run_command("rb", info);
			if (!push_in_vector(&info->cmd_c, RB, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		else
		{
			run_command("rrb", info);
			if (!push_in_vector(&info->cmd_c, RRB, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		i++;
	}
}

void		to_a(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->place.steps_to_a)
	{
		if (info->place.way_to_a == 't')
		{
			run_command("ra", info);
			if (!push_in_vector(&info->cmd_c, RA, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		else
		{
			run_command("rra", info);
			if (!push_in_vector(&info->cmd_c, RRA, sizeof(char)))
				clean_and_exit(info, 'm');
		}
		i++;
	}
	if (info->b)
	{
		run_command("pa", info);
		if (!push_in_vector(&info->cmd_c, PA, sizeof(char)))
			clean_and_exit(info, 'm');
	}
}

int			all_to_a(t_info *info)
{
	t_place	cur;
	t_stack	*ptr;

	ptr = info->b;
	ft_bzero(&cur, sizeof(cur));
	while (ptr)
	{
		steps_b(info->b, &cur, ptr->value);
		steps_a(info->a, &cur, ptr->value);
		if (!info->place.way_to_a || (cur.steps_to_a + cur.steps_to_b <\
		info->place.steps_to_b + info->place.steps_to_a))
			info->place = cur;
		ptr = ptr->next;
	}
	set_rr(&info->place);
	do_rr(info);
	to_top_b(info);
	to_a(info);
	ft_bzero(&info->place, sizeof(cur));
	if (info->b)
		all_to_a(info);
	return (1);
}
