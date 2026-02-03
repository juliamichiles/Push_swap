/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:35:38 by juliatav          #+#    #+#             */
/*   Updated: 2026/01/16 18:49:55 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"
#include "push_swap.h"

#include <stdio.h>//REMOVE!!!
void	print_stack(t_stack *stack)//REMOVE ME!!!!
{
	int	i = 0;
	while (stack)
	{
		printf("o-----NODE%d-----o\n", i);
		printf("| value: %d\t|\n", stack->value);
		printf("| index: %d\t|\n", stack->index);
		printf("| pos: %d\t|\n", stack->pos);
		printf("| target: %d\t|\n", stack->target);
		printf("|cost_a: %d\t|\n", stack->cost_a);
		printf("|cost_b: %d\t|\n", stack->cost_b);
		printf("o---------------o\n");
		stack = stack->next;
		i++;
	}
}


int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	*tab;
	int	size;

	size = 0;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	tab = normalize_input(ac, av, &size);//also sets a value to tab
	if (!tab)
	{
		print_error();
		return (1);
		
	}
	if (!repeated_nums(tab, size))//move it to validation function
	{
		free(tab);
		print_error();
		return (1);
	}
	if (is_sorted(tab, size))//move it to validation function
	{
		free(tab);
		return (0);
	}
	stack_a = get_stack_a(tab, size);
	if (!stack_a)
	{
		free(tab);
		return (1);
	}
	printf("-> BEFORE:\n\n");//REMOVE!!
	print_stack(stack_a);
	printf("\n-> AFTER:\n[push_swap]\n");//REMOVE!!
	push_swap(&stack_a, &stack_b, size);
	printf("\n");//REMOVE!!
	print_stack(stack_a);
	free_stack(stack_a);
	free(tab);
	return (0);
}
