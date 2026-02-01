#include "helpers.h"
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
