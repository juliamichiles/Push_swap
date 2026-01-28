#include "helpers.h"
#include "push_swap.h"

//NOT TESTED!!
int	get_max(t_stack *a)
{
	int	max_index;
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	max_index = a->index;
	while (a)
	{
		if (a->index > max_index)
		{
			max_index = a->index;
			pos = i;
		}
		a = a->next;
		i++;
	}
	return (pos);
}

void	sort_3(t_stack **a)
{
	int	max;

	max = get_max(*a);
	if (max == 0)
		ra(a);
	else if (max == 1)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

//sort_5??
//shouldn't I handle sort_2 searetelly as well
//function that calls the actual algorithm or sort3/sort5
