#include "push_swap.h"

void		do_rr(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.rr)
	{
		if ((*info)->place.way_to_b == 't')
		{
			run_command("rr", a, b);
			if (!push_in_vector(&(*info)->cmd_c, RR, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else if ((*info)->place.way_to_b == 'b')
		{
			run_command("rrr", a, b);
			if (!push_in_vector(&(*info)->cmd_c, RRR, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
}

void		to_top_b(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.steps_to_b)
	{
		if ((*info)->place.way_to_b == 't')
		{
			run_command("rb", 0, b);
			if (!push_in_vector(&(*info)->cmd_c, RB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("rrb", 0, b);
			if (!push_in_vector(&(*info)->cmd_c, RRB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
}

void		to_a(t_stack **a, t_stack **b, t_info **info)
{
	int		i;

	i = 0;
	while (i < (*info)->place.steps_to_a)
	{
		if ((*info)->place.way_to_a == 't')
		{
			run_command("ra", a, 0);
			if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("rra", a, 0);
			if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		i++;
	}
	if ((*b))
	{
		run_command("pa", a, b);
		if (!push_in_vector(&(*info)->cmd_c, PA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

int			all_to_a2(t_stack **a, t_stack **b, t_info **info)
{
	t_place	cur;
	t_stack	*ptr;

	ptr = (*b);
	ft_bzero(&cur, sizeof(cur));
	while (ptr)
	{
		steps_b(b, &cur, ptr->value);
		steps_a(a, &cur, ptr->value);
		set_rr(&cur);
		if (!(*info)->place.way_to_a || (cur.steps_to_a + cur.steps_to_b <\
		(*info)->place.steps_to_b + (*info)->place.steps_to_a))
			(*info)->place = cur;
		ptr = ptr->next;
	}
	do_rr(a, b, info);
	to_top_b(a, b, info);
	to_a(a, b, info);
	ft_bzero(&(*info)->place, sizeof(cur));
	if ((*b))
		all_to_a2(a, b, info);
	return (1);
}
