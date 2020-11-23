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

void		get_commands(t_info *info)
{
	all_to_b(info);
	all_to_a(info);
	if (check_asc_order(info->a, 0))
		return ;
	if (!(is_slice(info->a)))
		clean_and_exit(info, 'm');
	sort_slice(info);
}
