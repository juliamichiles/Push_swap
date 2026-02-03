#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "../Libft/libft.h"
# include "helpers.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					pos;
	int					target;
	int					cost_a;
	int					cost_b;
	struct s_stack		*next;
}						t_stack;

void	push_swap(t_stack **a, t_stack **b, int size);

//validation:
int		is_sorted(int *tab, int size);
int		get_sorted_index(int *sorted, int size, int current);
int		repeated_nums(int *tab, int size);
int		*normalize_input(int ac, char *av[], int *size);
int		*tabdup(int *tab, int size);
void	sort_tab(int *tab, int size);

//operations:
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

//stack utils:
t_stack	*get_stack_a(int *tab, int size);
t_stack	*ft_lstlast(t_stack *lst);
void	update_pos(t_stack *stack);
void	free_stack(t_stack *stack);
void	lst_add_back(t_stack **stack, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
int		ft_lstsize(t_stack *lst);

//sorting helpers:
int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);

//small stacks:
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
#endif
