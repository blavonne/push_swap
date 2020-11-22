#include "push_swap.h"

void			to_b_rrb(t_stack **a, t_stack **b, t_info **info, int middle)
{
	int		value;

	while ((*a) && !is_slice((*a)))
	{
		run_command("rra", a, b, (*info)->flag);
		value = (*a)->value;
		if (value < middle)
		{
			if (!push_in_vector(&(*info)->cmd_c, RRA, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
			run_command("pb", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
		{
			run_command("ra", a, b, (*info)->flag);
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
			run_command("pb", a, b, (*info)->flag);
			if (!push_in_vector(&(*info)->cmd_c, PB, sizeof(char)))
				clean_and_exit(a, b, info, 'm');
		}
		else
			break ;
	}
}

void			do_ra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		print_a(a);
		run_command("ra", a, 0, (*info)->flag);
		if (!push_in_vector(&(*info)->cmd_c, RA, sizeof(char)))
			clean_and_exit(a, b, info, 'm');
	}
}

void			do_rra(t_stack **a, t_stack **b, t_info **info, int i)
{
	while (i--)
	{
		ft_printf("qwe\n");
		run_command("rra", a, 0, (*info)->flag);
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
	top = 0;
	bottom = -1;
	while (ptr)
	{
		if (bottom == -1 && ptr->value < middle)
		{
			top = len;
			bottom = 0;
		}
		if (!bottom && ptr->value < middle)
			bottom = len;
		len++;
		ft_printf("top %i bottom %i len %i\n", top, bottom, len);
		ptr = ptr->next;
	}
	if (top && bottom && top <= bottom)
		do_ra(a, b, info, top);
	if (top && bottom && top > bottom)
		do_rra(a, b, info, bottom);
}

void			all_to_b(t_stack **a, t_stack **b, t_info **info)
{
	int				middle_val;

	//ft_printf("all to b\n");
	while ((*a) && (*a)->next && (*a)->next->next && !(is_slice((*a))))
	{
		middle_val = get_middle(a, b, info);
		//ft_printf("try sa outer, middle is %i\n", middle_val);
		try_sa(a, b, info);
		while (check_mid((*a), middle_val) && !(is_slice((*a))))
		{
			//ft_printf("try sa inner\n");
			try_sa(a, b, info);
			//ft_printf("to_b_rb\n");
			to_b_rb(a, b, info, middle_val);
			try_sa(a, b, info);
			//ft_printf("to_b_rrb\n");
			to_b_rrb(a, b, info, middle_val);
			try_sa(a, b, info);
			//ft_printf("do_rotate\n");
			do_rotate(a, b, info, middle_val);
			//ft_printf("do_rotate end\n");
		}
	}
}
