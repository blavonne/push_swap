#include "push_swap.h"

void		print_b(t_stack *ptr_b)
{
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void		print_rr(t_stack *ptr_a, t_stack *ptr_b, char *color)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr_a)
	{
		if (i == 0 && ptr_a->next && (i = 1))
			ft_printf("%s%11d  %s", color, ptr_a->value, ANSI_RESET);
		else
			ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			if (j == 0 && (j = 1))
				ft_printf("%s%-11d%s\n", color, ptr_b->value, ANSI_RESET);
			else
				ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		if (j == 0 && (j = 1))
			ft_printf("%s%-11d%s\n", color, ptr_b->value, ANSI_RESET);
		else
			ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void		print_rb(t_stack *ptr_a, t_stack *ptr_b, char *color)
{
	int		i;

	i = 0;
	while (ptr_a)
	{
		ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			if (i == 0 && (i = 1))
				ft_printf("%s%-11d%s\n", color, ptr_b->value, ANSI_RESET);
			else
				ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	print_b(ptr_b);
}

void		print_ra(t_stack *ptr_a, t_stack *ptr_b, char *color)
{
	int		i;

	i = 0;
	while (ptr_a)
	{
		if (i == 0 && (i = 1))
			ft_printf("%s%11d  %s", color, ptr_a->value, ANSI_RESET);
		else
			ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	print_b(ptr_b);
}

void		print_sa(t_stack *ptr_a, t_stack *ptr_b)
{
	int		i;

	i = 0;
	while (ptr_a)
	{
		if (i == 0 && (i = 1))
			ft_printf("%s%11d  %s", ANSI_RED, ptr_a->value, ANSI_RESET);
		else if (i == 1 && (i = 2))
			ft_printf("%s%11d  %s", ANSI_BLUE, ptr_a->value, ANSI_RESET);
		else
			ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	print_b(ptr_b);
}

void		print_ss(t_stack *ptr_a, t_stack *ptr_b)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ptr_a)
	{
		if (i == 0 && ptr_a->next && (i = 1))
			ft_printf("%s%11d  %s", ANSI_RED, ptr_a->value, ANSI_RESET);
		else if (i == 1 && (i = 2))
			ft_printf("%s%11d  %s", ANSI_BLUE, ptr_a->value, ANSI_RESET);
		else
			ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			if (j == 0 && ptr_b->next && (j = 1))
				ft_printf("%s%-11d%s\n", ANSI_RED, ptr_b->value, ANSI_RESET);
			else if (j == 1 && (j = 2))
				ft_printf("%s%-11d%s\n", ANSI_BLUE, ptr_b->value, ANSI_RESET);
			else
				ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		if (j == 0 && ptr_b->next && (i = 1))
			ft_printf("%s%-11d%s\n", ANSI_RED, ptr_b->value, ANSI_RESET);
		else if (j == 1 && (j = 2))
			ft_printf("%s%-11d%s\n", ANSI_BLUE, ptr_b->value, ANSI_RESET);
		else
			ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void		print_sb(t_stack *ptr_a, t_stack *ptr_b)
{
	int		i;

	i = 0;
	while (ptr_a)
	{
		ft_printf("%11d  ", ptr_a->value);
		if (ptr_b)
		{
			if (i == 0 && ptr_b->next && (i = 1))
				ft_printf("%s%-11d%s\n", ANSI_RED, ptr_b->value, ANSI_RESET);
			else if (i == 1 && (i = 2))
				ft_printf("%s%-11d%s\n", ANSI_BLUE, ptr_b->value, ANSI_RESET);
			else
				ft_printf("%-11d\n", ptr_b->value);
			ptr_b = ptr_b->next;
		}
		else
			ft_printf("%-11s\n", ".");
		ptr_a = ptr_a->next;
	}
	while (ptr_b)
	{
		ft_printf("%11s  ", ".");
		if (i == 0 && ptr_b->next && (i = 1))
			ft_printf("%s%-11d%s\n", ANSI_RED, ptr_b->value, ANSI_RESET);
		else if (i == 1 && (i = 2))
			ft_printf("%s%-11d%s\n", ANSI_BLUE, ptr_b->value, ANSI_RESET);
		else
			ft_printf("%-11d\n", ptr_b->value);
		ptr_b = ptr_b->next;
	}
}

void		print_color(t_stack *ptr_a, t_stack *ptr_b, char *command)
{
	ft_strequ(command, "sa") ? print_sa(ptr_a, ptr_b) : 0;
	ft_strequ(command, "sb") ? print_sb(ptr_a, ptr_b) : 0;
	ft_strequ(command, "ss") ? print_ss(ptr_a, ptr_b) : 0;
	ft_strequ(command, "pa") ? print_ra(ptr_a, ptr_b, ANSI_YAN) : 0;
	ft_strequ(command, "ra") ? print_ra(ptr_a, ptr_b, ANSI_YELLOW) : 0;
	ft_strequ(command, "rra") ? print_ra(ptr_a, ptr_b, ANSI_GREEN) : 0;
	ft_strequ(command, "rrr") ? print_rr(ptr_a, ptr_b, ANSI_GREEN) : 0;
	ft_strequ(command, "rr") ? print_rr(ptr_a, ptr_b, ANSI_YELLOW) : 0;
	ft_strequ(command, "rb") ? print_rb(ptr_a, ptr_b, ANSI_YELLOW) : 0;
	ft_strequ(command, "pb") ? print_rb(ptr_a, ptr_b, ANSI_MAGENTA) : 0;
	ft_strequ(command, "rrb") ? print_rb(ptr_a, ptr_b, ANSI_GREEN) : 0;
}
