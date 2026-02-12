/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:50:43 by juliatav          #+#    #+#             */
/*   Updated: 2026/02/12 15:50:52 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

static void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	exec_move(t_stack **a, t_stack **b, t_stack *cheapest)
{
	int	cost_a;
	int	cost_b;

	cost_a = cheapest->cost_a;
	cost_b = cheapest->cost_b;
	rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(b, a);
}
