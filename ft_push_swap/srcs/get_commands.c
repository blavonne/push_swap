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

int			rotate(t_stack **a, t_info **info, char *cmd)
{
	t_stack			*copy;
	t_vector		*tmp;
	int				i;
	unsigned char	c;

	c = (ft_strequ(cmd, "ra")) ? RA : RRA;
	i = 0;
	tmp = NULL;
	if (!(copy = copy_stack((*a))))
		return (0);
	if (!(tmp = create_vector()))
	{
		destroy_stack(&copy);
		return (0);
	}
	while (!check_asc_order(copy, 0))
	{
		run_command(cmd, &copy, 0, (*info)->flag);
		push_in_vector(&tmp, c, sizeof(char));
		i++;
	}
	push_in_varr(info, tmp);
	destroy_stack(&copy);
	return (i);
}

int			sort_slice(t_stack **a, t_info **info)
{
	int		ra;
	int		rra;
	size_t	i;

	i = 0;
	if (!((*info)->cmd_arr = create_varr()))
		return (0);
	ra = rotate(a, info, "ra");
	rra = rotate(a, info, "rra");
	if (ra < rra)
	{
		cat_vectors(&(*info)->cmd_c, (*info)->cmd_arr[0]);
		while (i++ < (*info)->cmd_arr[0]->next)
			run_command("ra", a, 0, (*info)->flag);
	}
	else
	{
		while (i++ < (*info)->cmd_arr[1]->next)
			run_command("rra", a, 0, (*info)->flag);
		cat_vectors(&(*info)->cmd_c, (*info)->cmd_arr[1]);
	}
	if (!check_asc_order((*a), 0))
		return (0);
	return (1);
}

void		get_commands(t_stack **a, t_stack **b, t_info **info)
{
	all_to_b(a, b, info);
//	print_info(info);
	all_to_a(a, b, info);
	print_info(*info);
	if (check_asc_order((*a), 0))
		return ;
	if (!(is_slice(*a)))
		clean_and_exit(a, b, 0, 'm');
	if (!sort_slice(a, info))
		clean_and_exit(a, b, info, 'm');
}
