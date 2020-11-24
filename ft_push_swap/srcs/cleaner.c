/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:06 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:29:12 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		destroy_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ptr;

	if ((*stack))
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			ptr = tmp->next;
			free(tmp);
			tmp = NULL;
			tmp = ptr;
		}
		free(*stack);
		(*stack) = NULL;
	}
}

void		destroy_vector(t_vector **v)
{
	(*v) ? free((*v)->arr) : 0;
	(*v) ? (*v)->arr = NULL : 0;
	free(*v);
	(*v) = NULL;
}

void		clean_and_exit(t_info *info, char option)
{
	if (info)
	{
		(info->a) ? destroy_stack(&info->a) : 0;
		(info->b) ? destroy_stack(&info->b) : 0;
		(info->cmd_c) ? destroy_vector(&info->cmd_c) : 0;
	}
	put_errmsg_and_exit(option);
}
