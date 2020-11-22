/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_to_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:34:11 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:34:50 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ==========TRY_SA==========
** This func tries to do sa and if stack a is slice after that
** then it returns 1 otherwise it rolls back sa and returns 0
*/

int			try_sa(t_stack **a, t_stack **b, t_info **info)
{
	run_command("sa", a, 0);
	if (is_slice(*a))
	{
//		ft_printf("is slice\n");
		if (!push_in_vector(&(*info)->cmd_c, SA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		return (1);
	}
	else
		run_command("sa", a, 0);
	return (0);
}

/*
** ==========PB_FORWARD==========
** This func pushes numbers less than middle_val from top A to top B
*/

static void		pb_forward(t_stack **a, t_stack **b, t_info **info,\
		int middle_val)
{
	t_stack		*ptr;

	ptr = (*a);
	while (ptr && ptr->value < middle_val && !(is_slice((*a))) &&\
	!try_sa(a, b, info))
	{
		run_command("pb", a, b);
		if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		ptr = (*a);
	}
}

/*
** ==========PB_BACK==========
** This func pushes numbers less than middle_val from bottom A to top B
*/

static void		pb_back(t_stack **a, t_stack **b, t_info **info,\
		int middle_val)
{
	t_stack		*ptr;

	ptr = (*a);
	while (ptr && ptr->value < middle_val && !(is_slice((*a))) &&\
	!try_sa(a, b, info))
	{
		if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		run_command("pb", a, b);
		if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		run_command("rra", a, b);
		ptr = (*a);
	}
}

/*
** ==========RA==========
** This func rotates A till a-value is more or equal middle_val
*/

static void		ra(t_stack **a, t_stack **b, t_info **info, int middle_val)
{
	t_stack *ptr;

	ptr = (*a);
	while (ptr && check_mid(*a, middle_val) && ptr->value >= middle_val\
	&& !(is_slice((*a))) && !try_sa(a, b, info))
	{
		run_command("ra", a, b);
		if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
		ptr = (*a);
	}
}

/*
** ==========ALL_TO_B==========
** This func keeps the biggest sorted by ascending order numbers in A
** and other numbers puts in B
*/

void			all_to_b_old(t_stack **a, t_stack **b, t_info **info)
{
	int				middle_val;

	while ((*a) && (*a)->next && (*a)->next->next && !(is_slice((*a))))
	{
		middle_val = get_middle(a, b, info);
		try_sa(a, b, info);
		while (check_mid((*a), middle_val) && !(is_slice((*a))))
		{
			try_sa(a, b, info);
			ft_printf("###1 ");
			print_a(a);
			pb_forward(a, b, info, middle_val);
			run_command("rra", a, b);
			ft_printf("###2 ");
			print_a(a);
			try_sa(a, b, info);
			ft_printf("###3 ");
			print_a(a);
			pb_back(a, b, info, middle_val);
			run_command("ra", a, b);
			ft_printf("###4 ");
			print_a(a);
			ra(a, b, info, middle_val);
			ft_printf("###5 ");
			print_a(a);
		}
	}
	ft_printf("End cycle, ");
	print_a(a);
}

void		print_a(t_stack **a)
{
	t_stack	*ptr;

	ptr = (*a);
	ft_printf("A-status:\n");
	while (ptr)
	{
		ft_printf("%i\n", ptr->value);
		ptr = ptr->next;
	}
}