/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_and_cost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:53:30 by juliatav          #+#    #+#             */
/*   Updated: 2026/02/12 15:53:34 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*best_match;
	t_stack	*tmp_a;

	while (b)
	{
		tmp_a = a;
		best_match = NULL;
		while (tmp_a)
		{
			if (tmp_a->index > b->index
				&& (!best_match || tmp_a->index < best_match->index))
				best_match = tmp_a;
			tmp_a = tmp_a->next;
		}
		if (best_match)
			b->target = best_match;
		else
			b->target = find_min(a);
		b = b->next;
	}
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

void	set_costs(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (b)
	{
		b->cost_b = get_cost(b->pos, size_b);
		b->cost_a = get_cost(b->target->pos, size_a);
		b = b->next;
	}
}

int	ft_abs(int n)//doesn't handle int min properly
{
	if (n < 0)
		return (-n);
	return (n);
}

t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest;
	int		current;
	int		min;

	if (!b)
		return (NULL);
	cheapest = b;
	min = ft_abs(b->cost_a) + ft_abs(b->cost_b);
	b = b->next;
	while (b)
	{
		current = ft_abs(b->cost_a) + ft_abs(b->cost_b);
		if (current < min)
		{
			cheapest = b;
			min = current;
		}
		b = b->next;
	}
	return (cheapest);
}
