#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "helpers.h"

typedef struct	s_stack
{
	int			value;
	int			index;
	int			pos;
	int			target;
	int			cost_a;
	int			cost_b;
	struct s_stack		*next;
}	t_stack;


void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
