#include "push_swap.h"

void			to_b_rrb(t_stack **a, t_stack **b, t_info **info, int middle)
{
	int		value;

	while ((*a) && !is_slice((*a)))
	{
		run_command("rra", a, b);
		value = (*a)->value;
		if (value < middle)
		{
			if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
			run_command("pb", a, b);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("ra", a, b);
			break ;
		}
	}
}

void			to_b_rb(t_stack **a, t_stack **b, t_info **info, int middle)
{
	while ((*a) && !is_slice((*a)))
	{
		if ((*a)->value < middle)
		{
			run_command("pb", a, b);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		if ((*a)->value > middle)
			break ;
	}
}

void			do_ra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		run_command("ra", a, 0);
		if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void			do_rra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		run_command("rra", a, 0);
		if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void			do_rotate(t_stack **a, t_stack **b, t_info **info, int middle)
{
	int		len;
	int		top;
	int		bottom;
	t_stack	*ptr;

	ptr = (*a);
	len = 0;
	bottom = 0;
	while (ptr)
	{
		if (!bottom && ptr->value < middle)
		{
			top = len;
			bottom = -1;
		}
		if (bottom && ptr->value < middle)
			bottom = len;
		len++;
		ptr = ptr->next;
	}
	bottom > 0 ? bottom = len - bottom : 0;
	if (top <= bottom)
		do_ra(a, b, info, top);
	else
		do_rra(a, b, info, bottom);
}

void			all_to_b(t_stack **a, t_stack **b, t_info **info)
{
	int				middle_val;

	while ((*a) && (*a)->next && (*a)->next->next && !(is_slice((*a))))
	{
		middle_val = get_middle(a, b, info);
		try_sa(a, b, info);
		while (check_mid((*a), middle_val) && !(is_slice((*a))))
		{
			try_sa(a, b, info);
			to_b_rb(a, b, info, middle_val);
			to_b_rrb(a, b, info, middle_val);
			if (check_mid((*a), middle_val))
				do_rotate(a, b, info, middle_val);
		}
	}
	ft_printf("End cycle, ");
	print_a(a);
}
