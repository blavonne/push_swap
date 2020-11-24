/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:25:16 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:25:40 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_info *info)
{
	size_t			i;
	unsigned char	*arr;
	int				fd;

	i = 0;
	fd = 1;
	if (info->flag & TO_FILE && info->to_file)
		fd = open(info->to_file, O_CREAT | O_WRONLY | O_TRUNC);
	if ((info->flag & TO_FILE && !info->to_file) || fd < 0)
		clean_and_exit(info, 'f');
	arr = info->cmd_c->arr;
	while (i < info->cmd_c->next)
	{
		arr[i] == RB ? ft_putendl_fd("rb", fd) : 0;
		arr[i] == RA ? ft_putendl_fd("ra", fd) : 0;
		arr[i] == SA ? ft_putendl_fd("sa", fd) : 0;
		arr[i] == RRA ? ft_putendl_fd("rra", fd) : 0;
		arr[i] == RRB ? ft_putendl_fd("rrb", fd) : 0;
		arr[i] == PA ? ft_putendl_fd("pa", fd) : 0;
		arr[i] == PB ? ft_putendl_fd("pb", fd) : 0;
		arr[i] == RR ? ft_putendl_fd("rr", fd) : 0;
		arr[i] == RRR ? ft_putendl_fd("rrr", fd) : 0;
		i++;
	}
	close(fd);
}
