/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:41:22 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:41:24 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			debug_flag(char *str)
{
	if (ft_strequ(str, "-v"))
		return (1);
	return (0);
}

int					get_number(char *str, long long *number)
{
	int				sign;
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			(*number) = (*number) * 10 + str[i] - '0';
		i++;
	}
	(*number) *= sign;
	if ((*number) < INT_MIN || (*number) > INT_MAX)
		return (0);
	return (1);
}

void				check_duplicates(t_stack **stack)
{
	t_stack		*cur;
	t_stack		*head;

	head = (*stack);
	while (head->next)
	{
		cur = head->next;
		{
			while (cur)
			{
				if (cur->value == head->value)
					clean_and_exit(stack, 0, 0, 'd');
				cur = cur->next;
			}
		}
		head = head->next;
	}
}

t_stack				*read_argv(int argc, char **argv, int *flag)
{
	int				i;
	t_stack			*stack;
	long long int	number;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || ft_strlen(argv[i]) > 11)
			return (NULL);
		if (ft_isnumber(argv[i]))
		{
			if (!get_number(argv[i], &number))
				return (NULL);
			push_in_stack(&stack, (int)number);
		}
		else if (!(*flag) && debug_flag(argv[i]))
			*flag = 1;
		else if (!(try_to_split(argv[i], &stack)))
				return (NULL);
		i++;
	}
	check_duplicates(&stack);
	return (stack);
}
