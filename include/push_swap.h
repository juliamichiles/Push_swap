#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					pos;
	int					cost_a;
	int					cost_b;
	struct s_stack		*target;
	struct s_stack		*next;
}						t_stack;

void	push_swap(int *tab, int size);

//helpers:
void	print_error(void);
int		count_tokens(char *tokens[]);
int		*tokens_to_tab(char *tokens[]);
void	free_tokens(char *tokens[]);

//validation:
int		is_sorted(int *tab, int size);
int		get_sorted_index(int *sorted, int size, int current);
int		*normalize_input(int ac, char *av[], int *size);
int		*tabdup(int *tab, int size);
void	sort_tab(int *tab, int size);
int		*validate(int ac, char *av[], int *size);
int		check_tokens(char **tokens);

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
t_stack	*find_min(t_stack *stack);
//add int is_sorted(t_stack *stack);
//add int is_rev_sorted(t_stack *stack);

//small stacks:
void	sort_2(t_stack **stack);
void	sort_3(t_stack **stack);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);

//costs and targets:
t_stack *find_cheapest(t_stack *b);
int		ft_abs(int n);
void	set_costs(t_stack *a, t_stack *b);
int		get_cost(int pos, int size);
void	set_target(t_stack *a, t_stack *b);

void	exec_move(t_stack **a, t_stack **b, t_stack *cheapest);
void	rotate_stack(t_stack **a);
void	turk_sort(t_stack **a, t_stack **b);

#endif
