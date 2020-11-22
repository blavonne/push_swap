/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blavonne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 01:40:48 by blavonne          #+#    #+#             */
/*   Updated: 2020/08/22 01:40:51 by blavonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clean_split(char ***matrix)
{
	int		i;

	i = 0;
	while ((**matrix) && (*matrix) && (*matrix)[i])
	{
		free((*matrix)[i]);
		(*matrix)[i] = NULL;
		i++;
	}
	if ((*matrix))
	{
		free((*matrix));
		(*matrix) = NULL;
	}
}

static char	set_delimiter(char *str)
{
	int		i;
	char	delimiter;

	i = 0;
	if (!str)
		return (0);
	if (!ft_issign(str[0]) && !ft_isdigit(str[0]))
		return (0);
	else
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	delimiter = str[i];
	return (delimiter);
}

int			check_split(char *res, t_stack **stack, long long int *number)
{
	if (ft_isnumber(res))
	{
		if (get_number(res, number))
			push_in_stack(stack, (int)(*number));
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			try_to_split(char *str, t_stack **stack)
{
	char			delimiter;
	int				i;
	char			**res;
	long long int	number;

	res = NULL;
	if (!(delimiter = set_delimiter(str)))
		return (0);
	if (!(res = ft_strsplit(str, delimiter)))
		return (0);
	i = 0;
	while (res[i])
	{
		if (check_split(res[i], stack, &number))
			i++;
		else
		{
			clean_split(&res);
			return (0);
		}
	}
	clean_split(&res);
	return (1);
}
