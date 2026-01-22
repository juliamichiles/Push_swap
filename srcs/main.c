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

//#include "validation.h"
#include "helpers.h"
#include "push_swap.h"

int	main(int ac, char *av[])
{
	int	*tab;
	int	size;

	size = 0;
	if (ac < 2)
		return (1);
	tab = normalize_input(ac, av, &size);
	if (!tab)
	{
		print_error();
		return (1);
		
	}
	if (!repeated_nums(tab))
		print_error();
	else 
		//chama o push_swap ou oq quer que seja
	free(tab);
	return (0);
}
