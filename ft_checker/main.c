/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:42:07 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:42:10 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_commands(t_info *info)
{
	char	*cmd;

	cmd = NULL;
	while (get_next_line(0, &cmd) > 0)
	{
		if (!check_command(cmd))
			clean_and_exit(info, 'c');
		run_command(cmd, info);
		free(cmd);
	}
	free(cmd);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (argc == 1)
		return (0);
	ft_printf("qwe\n");
	info_init(&info);
	info.flag = 1; //re
	ft_printf("qwe\n");
	print_status(&info, "qwe");
	read_argv(argc, argv, &info);
	print_status(&info, "qwe");
	ft_printf("qwe\n");
	check_duplicates(&info);
	print_status(&info, "qwe");
	read_commands(&info);
	ft_printf("qwe\n");
	check_asc_order(info.a, info.b) ? ft_printf("OK\n") : ft_printf("KO\n");
	clean_and_exit(&info, 0);
	return (0);
}
