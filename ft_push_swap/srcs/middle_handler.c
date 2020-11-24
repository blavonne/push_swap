/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 02:39:05 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 02:39:09 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*get_arr(t_info *info, int size)
{
	t_stack	*ptr;
	int		*arr;
	int		i;

	if (!(arr = (int *)malloc((sizeof(int) * size))))
		clean_and_exit(info, 'm');
	i = 0;
	ptr = info->a;
	while (arr && ptr && i < size)
	{
		arr[i] = ptr->value;
		ptr = ptr->next;
		i++;
	}
	return (arr);
}

static int		set_size(t_stack *a)
{
	int		i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int				get_middle(t_info *info)
{
	int		*arr;
	int		middle;
	int		size;

	size = set_size(info->a);
	arr = get_arr(info, size);
	if ((arr = timsort(arr, size)))
	{
		middle = arr[size / 2];
		free(arr);
		return (middle);
	}
	else
	{
		free(arr);
		clean_and_exit(info, 'm');
		return (0);
	}
}

int				check_mid(t_stack *a, int middle)
{
	while (a)
	{
		if (a->value < middle)
			return (1);
		a = a->next;
	}
	return (0);
}
