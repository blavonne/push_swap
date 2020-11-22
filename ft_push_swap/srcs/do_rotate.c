/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:33 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:30:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			do_ra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		run_command("ra", a, 0, (*info)->flag);
		if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void			do_rra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		run_command("rra", a, 0, (*info)->flag);
		if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void			do_rotate(t_stack **a, t_stack **b, t_info **info, int middle)
{
	int		len;
	int		top;
	int		bottom;
	t_stack	*ptr;

	ptr = (*a);
	len = 0;
	top = 0;
	bottom = -1;
	while (ptr)
	{
		if (bottom == -1 && ptr->value < middle)
		{
			top = len;
			bottom = 0;
		}
		if (!bottom && ptr->value < middle)
			bottom = len;
		len++;
		ptr = ptr->next;
	}
	if (top && bottom && top <= bottom)
		do_ra(a, b, info, top);
	else if (top && bottom && top > bottom)
		do_rra(a, b, info, bottom);
}
