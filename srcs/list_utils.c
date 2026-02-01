#include "push_swap.h"
#include "helpers.h"

t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->pos = -1;
	node->target = -1;
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

t_stack	*tab_to_stack(int *tab, int *sorted, int size)
{
	t_stack	*node;
	t_stack	*a;
	int		index;
	int		i;

	a = NULL;
	i = 0;
	while (i < size)
	{
		index = get_sorted_index(sorted, size, tab[i]);
		node = new_node(tab[i], index);
		if (!node)
		{
			free_stack(a);
			return (NULL);
		}
		lst_add_back(&a, node);
		i++;
	}
	return (a);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	update_pos(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

t_stack	*get_stack_a(int *tab, int size)
{
	t_stack	*stack_a;
	int		*sorted;

	sorted = tabdup(tab, size);
	if (!sorted)
		return (NULL);
	sort_tab(sorted, size);
	stack_a = tab_to_stack(tab, sorted, size);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}
