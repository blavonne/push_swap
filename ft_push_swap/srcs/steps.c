#include "push_swap.h"

void		steps_b(t_stack **b, t_place *cur, int value)
{
	t_stack	*ptr;
	int		len;

	len = 0;
	ptr = (*b);
	cur->way_to_b = 't';
	while (ptr)
	{
		if (ptr->value == value)
			cur->steps_to_b = len;
		len++;
		ptr = ptr->next;
	}
	if (len - cur->steps_to_b < cur->steps_to_b)
	{
		cur->steps_to_b = len - cur->steps_to_b;
		cur->way_to_b = 'b';
	}
}

void		steps_a(t_stack **a, t_place *cur, int value)
{
	t_stack	*ptr;
	int		min;
	int		set;
	int		len;

	set = 0;
	len= 0;
	ptr = (*a);
	cur->way_to_a = 't';
	while (ptr)
	{
		if (!set && ptr->value > value)
		{
			cur->steps_to_a = len;
			min = ptr->value;
			set = 1;
		}
		if (set && ptr->value < min && ptr->value > value)
		{
			min = ptr->value;
			cur->steps_to_a = len;
		}
		len++;
		ptr = ptr->next;
	}
	if (len - cur->steps_to_a < cur->steps_to_a)
	{
		cur->steps_to_a = len - cur->steps_to_a;
		cur->way_to_a = 'b';
	}
}

void		set_rr(t_place *place)
{
	int rr;

	if (place->way_to_b == place->way_to_a)
	{
		rr = (int)ft_min(place->steps_to_a, place->steps_to_b);
		place->steps_to_a -= rr;
		place->steps_to_b -= rr;
		place->rr = rr;
	}
}
