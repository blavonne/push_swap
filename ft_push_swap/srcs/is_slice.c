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

int		check_point(t_stack *a, t_stack *point, char order)
{
	t_stack	*ptr;
	int		i;

	ptr = point;
	if (order == 'a')
		i = (check_asc_order(point, 0)) ? 1 : 0;
	while (ptr && ptr->next)
		ptr = ptr->next;
	if ((i == 1 && ptr && ptr->value < a->value) || (i == 2 && ptr &&
	ptr->value > a->value))
		return (1);
	ft_printf("tut?\n");
	return (0);
}

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
