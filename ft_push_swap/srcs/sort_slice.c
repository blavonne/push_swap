/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:33 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:30:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_rra(t_info *info, int steps)
{
	while (steps--)
	{
		run_command("rra", info);
		if (!push_in_vector(info->cmd_c, RRA, sizeof(char)))
			clean_and_exit(info, 'm');
	}
}

static void	rotate_ra(t_info *info, int steps)
{
	while (steps--)
	{
		run_command("ra", info);
		if (!push_in_vector(info->cmd_c, RA, sizeof(char)))
			clean_and_exit(info, 'm');
	}
}

void		sort_slice(t_info *info)
{
	int		len;
	int		min;
	int		steps;
	t_stack	*ptr;

	ptr = info->a;
	len = 0;
	min = ptr->value;
	while (ptr)
	{
		if (ptr->value < min)
		{
			min = ptr->value;
			steps = len;
		}
		len++;
		ptr = ptr->next;
	}
	if (len - steps < steps)
		rotate_rra(info, len - steps);
	else
		rotate_ra(info, steps);
}
