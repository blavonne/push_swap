#include "push_swap.h"

static void		print_one(t_stack *ptr_a, t_stack *ptr_b)
{
	while (ptr_a)
	{
		ft_printf("%11d  ", ptr_a->value);
		ft_printf("%-11s", ".");
		ptr_a = ptr_a->next;
		ft_printf("\n");
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

static void		print_both(t_stack *ptr_a, t_stack *ptr_b)
{
	while (ptr_a)
	{
		ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			ft_printf("%-11d", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s", ".");
		ptr_a = ptr_a->next;
		ft_printf("\n");
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void		print_status(t_stack **a, t_stack **b, char *command, int flag)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	if (flag)
	{
		ptr_a = a ? (*a) : 0;
		ptr_b = b ? (*b) : 0;
		ft_printf("=========================\n");
		if (ft_strlen(command) == 2)
			ft_printf("|    Run command %s     |\n", command);
		else if (ft_strlen(command) == 3)
			ft_printf("|    Run command %s    |\n", command);
		ft_printf("=========================\n");
		ft_printf("%11s  %-11s\n", "A", "B");
		if (flag == 2)
			print_one(ptr_a, ptr_b);
		else if (flag == 1)
			print_both(ptr_a, ptr_b);
		ft_printf("\n");
	}
}
