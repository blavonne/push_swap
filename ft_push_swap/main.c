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
	t_info	info;

	if (argc == 1)
		return (0);
	ft_bzero(&info, sizeof(struct s_info));
	read_argv(argc, argv, &info);
	check_duplicates(&info);
	get_commands(&info);
	if (!info.flag)
		print_info(&info);
	clean_and_exit(&info, 0);
	return (0);
}
