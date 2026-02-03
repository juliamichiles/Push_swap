#include "helpers.h"
#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int	max;

	max = get_max_pos(*stack);
	if (max == 0)
		ra(stack);
	else if (max == 1)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_2(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_4(t_stack **a, t_stack **b)
{
    int min_pos;
	int	size;

	size = 4;
	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
	pb(a, b);
	sort_3(a);
	pa(b, a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	size = 5;
	while (size > 3)
	{
		min_pos = get_min_pos(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
