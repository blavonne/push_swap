/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_slice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:26:57 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:27:16 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_slice(t_stack *a)
{
	t_stack	*ptr;
	int		max;
	int		min;
	int		cur;

	ptr = a;
	min = a->value;
	while (ptr->next && ptr->value < ptr->next->value)
		ptr = ptr->next;
	max = ptr->value;
	ptr = ptr->next;
	while (ptr)
	{
		cur = ptr->value;
		if (!(cur < min && cur < max))
			return (0);
		if (ptr->next && ptr->next->value < cur)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
