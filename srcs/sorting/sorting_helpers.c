#include "push_swap.h"

int	get_max_pos(t_stack *stack)
{
	int	max_index;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	max_index = stack->index;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

int	get_min_pos(t_stack *stack)
{
	int	min_index;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			pos = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack->index < min->index)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	is_rotate_sorted(t_stack *stack)
{
	t_stack	*current;
	t_stack *min;
	int		drops;

	drops = 0;
	current = stack;
	min = find_min(stack);
	while (current->next)
	{
		 if (current->index > current->next->index)
		 {
			if (current->next != min)
				return (0);
			drops++;
		 }
		 current = current->next;
	}
	return (drops <= 1);
}
