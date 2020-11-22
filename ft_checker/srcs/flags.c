#include "push_swap.h"

int			is_flag(char *str)
{
	if (ft_strequ(str, "-v"))
		return (1);
	return (0);
}

void		print_status(t_stack **a, t_stack **b, char *command)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = a ? (*a) : 0;
	ptr_b = b ? (*b) : 0;
	ft_printf("===============\n");
	ft_printf("Run command %s\n", command);
	ft_printf("===============\n");
	ft_printf("%6s  %-6s\n", "A", "B");
	while (ptr_a)
	{
		ft_printf("%6d  ", ptr_a->value);
		if (ptr_b)
		{
			ft_printf("%-6d", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-6s", ".");
		ptr_a = ptr_a->next;
		ft_printf("\n");
	}
	while (ptr_b)
	{
		ft_printf("%6s  ", ".");
		ft_printf("%-6d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
	ft_printf("\n");
}
