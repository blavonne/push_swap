/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:06 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:29:12 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		steps_b(t_stack *b, t_place *cur, int value)
{
	t_stack	*ptr;
	int		len;

	len = 0;
	ptr = b;
	cur->way_to_b = 't';
	while (ptr)
	{
		if (ptr->value == value)
			cur->steps_to_b = len;
		len++;
		ptr = ptr->next;
	}
	if (len - cur->steps_to_b < cur->steps_to_b)
	{
		cur->steps_to_b = len - cur->steps_to_b;
		cur->way_to_b = 'b';
	}
}

void		set_rr(t_place *place)
{
	int rr;

	if (place->way_to_b == place->way_to_a)
	{
		rr = (int)ft_min(place->steps_to_a, place->steps_to_b);
		place->steps_to_a -= rr;
		place->steps_to_b -= rr;
		place->rr = rr;
	}
}
