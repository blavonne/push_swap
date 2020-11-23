/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commander.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:03 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:06 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		run_r(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*new_head;
	t_stack	*ptr;

	if ((*stack) && (*stack)->next)
	{
		old_head = (*stack);
		new_head = (*stack)->next;
		ptr = (*stack);
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = old_head;
		old_head->next = NULL;
		(*stack) = new_head;
	}
}

static void		run_s(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*tmp;

	if ((*stack) && (*stack)->next)
	{
		old_head = (*stack);
		tmp = (*stack)->next;
		old_head->next = tmp->next;
		tmp->next = old_head;
		(*stack) = tmp;
	}
}

static void		run_p(t_stack **dest, t_stack **src)
{
	t_stack	*src_to_push;
	t_stack	*src_new_head;

	if (*src)
	{
		src_to_push = (*src);
		src_new_head = (*src)->next;
		src_to_push->next = (*dest);
		(*dest) = src_to_push;
		(*src) = src_new_head;
	}
}

static void		run_rr(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	tmp = (*stack);
	ptr = (*stack);
	if ((*stack) && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		while (ptr->next && ptr->next->value != tmp->value)
			ptr = ptr->next;
		ptr->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void			run_command(char *command, t_info *info)
{
	ft_strequ("sa", command) ? run_s(&info->a) : 0;
	ft_strequ("sb", command) ? run_s(&info->b) : 0;
	if (ft_strequ("ss", command))
	{
		run_s(&info->a);
		run_s(&info->b);
	}
	ft_strequ("pa", command) ? run_p(&info->a, &info->b) : 0;
	ft_strequ("pb", command) ? run_p(&info->b, &info->a) : 0;
	ft_strequ("ra", command) ? run_r(&info->a) : 0;
	ft_strequ("rb", command) ? run_r(&info->b) : 0;
	if (ft_strequ("rr", command))
	{
		run_r(&info->a);
		run_r(&info->b);
	}
	ft_strequ("rra", command) ? run_rr(&info->a) : 0;
	ft_strequ("rrb", command) ? run_rr(&info->b) : 0;
	if (ft_strequ("rrr", command))
	{
		run_rr(&info->a);
		run_rr(&info->b);
	}
	print_status(info, command);
}
