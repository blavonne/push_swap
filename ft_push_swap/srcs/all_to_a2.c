#include "push_swap.h"

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
	if ((*b))
		all_to_a2(a, b, info);
	return (1);
}