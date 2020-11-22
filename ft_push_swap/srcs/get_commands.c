/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:29:33 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:30:17 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_commands(t_stack **a, t_stack **b, t_info **info)
{
	all_to_b(a, b, info);
	all_to_a(a, b, info);
	if (check_asc_order((*a), 0))
		return ;
	if (!(is_slice(*a)))
		clean_and_exit(a, b, 0, 'm');
	sort_slice(a, b, info);
}
