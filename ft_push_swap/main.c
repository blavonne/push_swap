/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:25:16 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:25:40 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_info	*info;

	if (argc == 1)
		return (0);
	if (!(info = create_main_struct()))
		clean_and_exit(&a, &b, &info, 'm');
	a = read_argv(argc, argv, &info->flag);
	if (a)
	{
		b = NULL;
		if (check_asc_order(a, b))
		{
			clean_and_exit(&a, &b, 0, 0);
			return (0);
		}
		get_commands(&a, &b, &info);
		if (!info->flag)
			print_info(info);
	}
	clean_and_exit(&a, &b, &info, 0);
	return (0);
}
