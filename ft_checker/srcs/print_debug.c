/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_both(t_stack *ptr_a, t_stack *ptr_b)
{
	while (ptr_a)
	{
		ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			ft_printf("%-11d", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s", ".");
		ptr_a = ptr_a->next;
		ft_printf("\n");
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void			print_debug(t_info *info, char *command)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	if (info->flag & DEBUG || info->flag & COLOR)
	{
		ptr_a = info->a;
		ptr_b = info->b;
		ft_printf("=========================\n");
		if (ft_strlen(command) == 2)
			ft_printf("|    Run command %s     |\n", command);
		else if (ft_strlen(command) == 3)
			ft_printf("|    Run command %s    |\n", command);
		ft_printf("=========================\n");
		ft_printf("%11s  %-11s\n", "A", "B");
		(info->flag & COLOR) ? print_color(ptr_a, ptr_b, command) :\
		print_both(ptr_a, ptr_b);
		ft_printf("\n");
	}
}
