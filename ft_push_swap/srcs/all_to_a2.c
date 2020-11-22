#include "push_swap.h"

int			all_to_a2(t_stack **a, t_stack **b, t_info **info)
{
	t_place	cur;
	t_stack	*ptr;

	ptr = (*b);
	ft_bzero(&cur, sizeof(cur));
	while (ptr)
	{
		to_top_rb(a, b, &cur);
		to_top_rrb(a, b, &cur);
		to_a_ra(a, b, &cur);
		to_a_rra(a, b, &cur);
		set_rr(&cur);
		if (!(*info)->place.way_to_a || (cur.steps_to_a + cur.steps_to_b <\
		(*info)->place.steps_to_b + (*info)->place.steps_to_a))
			(*info)->place = cur;
		ptr = ptr->next;
	}
	if ((*b))
		all_to_a2(a, b, info);
	return (1);
}
