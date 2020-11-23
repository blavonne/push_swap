/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:06 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:29:12 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_a_way(t_place *cur, int len)
{
	if (len - cur->steps_to_a < cur->steps_to_a)
	{
		cur->steps_to_a = len - cur->steps_to_a;
		cur->way_to_a = 'b';
	}
}

void		steps_a(t_stack *a, t_place *cur, int value)
{
	t_stack	*ptr;
	int		min;
	int		set;
	int		len;

	set = 0;
	len = 0;
	ptr = a;
	cur->way_to_a = 't';
	while (ptr)
	{
		if (!set && ptr->value > value && (set = 1))
		{
			cur->steps_to_a = len;
			min = ptr->value;
		}
		if (set && ptr->value < min && ptr->value > value)
		{
			min = ptr->value;
			cur->steps_to_a = len;
		}
		len++;
		ptr = ptr->next;
	}
	reset_a_way(cur, len);
}
