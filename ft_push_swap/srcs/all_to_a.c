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

void		do_rr(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.rr)
	{
		if ((*info)->place.way_to_b == 't' && (*info)->place.way_to_a == 't')
		{
			run_command("rr", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RR, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else if ((*info)->place.way_to_b == 'b' &&\
		(*info)->place.way_to_a == 'b')
		{
			run_command("rrr", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RRR, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
}

void		to_top_b(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.steps_to_b)
	{
		if ((*info)->place.way_to_b == 't')
		{
			run_command("rb", 0, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("rrb", 0, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RRB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
}

void		to_a(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.steps_to_a)
	{
		if ((*info)->place.way_to_a == 't')
		{
			run_command("ra", a, 0, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("rra", a, 0, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
	if ((*b))
	{
		run_command("pa", a, b, (*info)->flag);
		if (!push_in_vector(&(*info)->cmd_c, PA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void		print_place(t_place place)
{
	ft_printf("Place:\n");
	ft_printf("way to a %c, steps %i\nway to b %c, steps %i\nrr %i\n",\
	place.way_to_a, place.steps_to_a, place.way_to_b, place.steps_to_b,\
	place.rr);
}

int			all_to_a(t_stack **a, t_stack **b, t_info **info)
{
	t_place	cur;
	t_stack	*ptr;

	ptr = (*b);
	ft_bzero(&cur, sizeof(cur));
	while (ptr)
	{
		steps_b(b, &cur, ptr->value);
		steps_a(a, &cur, ptr->value);
		if (!(*info)->place.way_to_a || (cur.steps_to_a + cur.steps_to_b <\
		(*info)->place.steps_to_b + (*info)->place.steps_to_a))
			(*info)->place = cur;
		ptr = ptr->next;
	}
	set_rr(&(*info)->place);
//	print_status(a, b, "до rr");
//	print_place((*info)->place);
	do_rr(a, b, info);
//	print_status(a, b, "после rr");
	to_top_b(a, b, info);
	to_a(a, b, info);
	ft_bzero(&(*info)->place, sizeof(cur));
	if ((*b))
		all_to_a(a, b, info);
	return (1);
}
