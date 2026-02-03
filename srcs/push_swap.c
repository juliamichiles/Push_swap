#include "helpers.h"
#include "push_swap.h"

#include <stdio.h>//REMOVE!!
void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size < 2)//should be in main, not here
		return ;
	if (size == 2)
		sort_2(a);
	if (size == 3)
		sort_3(a);
	if (size == 4)
		sort_4(a, b);
	if (size == 5)
		sort_5(a, b);
	if (size > 5)
	{
		//calls turk algo.
		printf("I can't sort this yet :(\n");//REMOVE!!
	}
}
