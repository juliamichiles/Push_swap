#include "push_swap.h"

static void	pb_until_3(t_stack **a, t_stack **b)
{
	while (ft_lstsize(*a) > 3)
		pb(a, b);
}

static void	return_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (*b)
	{
		update_pos(*a);
		update_pos(*b);
		set_target(*a, *b);
		set_costs(*a, *b);
		cheapest = find_cheapest(*b);
		exec_move(a, b, cheapest);
	}
}

void	rotate_stack(t_stack **a)
{
	int	size;
	int	min;

	update_pos(*a);
	size = ft_lstsize(*a);
	min = get_min_pos(*a);
	if (min <= size / 2)
	{
		while (min--)
			ra(a);
	}
	else
	{
		min = size - min;
		while (min--)
			rra(a);
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	if (is_rotate_sorted(*a))
	{
		rotate_stack(a);
		return ;
	}
	pb_until_3(a, b);
	sort_3(a);
	return_to_a(a, b);
	rotate_stack(a);
}

void	push_swap(int *tab, int size)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = get_stack_a(tab, size);
	if (!a)
	{
		print_error();
		return ;
	}
	if (size == 2)
		sort_2(&a);
	if (size == 3)
		sort_3(&a);
	if (size == 4)
		sort_4(&a, &b);
	if (size == 5)
		sort_5(&a, &b);
	if (size > 5)
		turk_sort(&a, &b);
	free_stack(a);
	free_stack(b);
}
