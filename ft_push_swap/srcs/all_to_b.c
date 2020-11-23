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

int				try_sa(t_stack **a, t_stack **b, t_info **info)
{
	if ((*a) && (*a)->next && (*a)->next->next)
	{
		run_command("sa", a, b, (*info)->flag);
		if (is_slice(*a))
		{
			if (!push_in_vector(&(*info)->cmd_c, SA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
			return (1);
		}
		else
			run_command("sa", a, b, (*info)->flag);
	}
	return (0);
}

void			to_b_rrb(t_stack **a, t_stack **b, t_info **info, int middle)
{
	int		value;

	while ((*a) && !is_slice((*a)))
	{
		run_command("rra", a, b, (*info)->flag);
		value = (*a)->value;
		if (value < middle)
		{
			if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
			run_command("pb", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("ra", a, b, (*info)->flag);
			break ;
		}
	}
}

void			to_b_rb(t_stack **a, t_stack **b, t_info **info, int middle)
{
	while ((*a) && !is_slice((*a)))
	{
		if ((*a)->value < middle)
		{
			run_command("pb", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
			break ;
	}
}

void			all_to_b(t_stack **a, t_stack **b, t_info **info)
{
	int				middle_val;

	while ((*a) && (*a)->next && (*a)->next->next && !(is_slice((*a))))
	{
		middle_val = get_middle(a, b, info);
		try_sa(a, b, info);
		while (check_mid((*a), middle_val) && !(is_slice((*a))))
		{
			try_sa(a, b, info);
			to_b_rb(a, b, info, middle_val);
			try_sa(a, b, info);
			to_b_rrb(a, b, info, middle_val);
			try_sa(a, b, info);
			do_rotate(a, b, info, middle_val);
		}
	}
}
