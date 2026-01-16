/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:35:06 by juliatav          #+#    #+#             */
/*   Updated: 2026/01/16 18:35:11 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

void	free_tokens(char *tokens[])
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	count_tokens(char *tokens[])
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	*tokens_to_tab(char *tokens[])//convert directly to list instead?
{
	int	*tab;//change to stack
	int	value;
	int	count;
	int	i;

	i = 0;
	count = count_tokens(tokens);
	tab = malloc(count * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		if (!safe_atoi(tokens[i], &value))
		{
			free(tab);
			return (NULL);
		}
		tab[i] = value;
		i++;
	}
	return (tab);
}

int	safe_atoi(const char *str, int *out)
{
	long	n;
	int	sign;
	int	digit;

	n = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		digit = *str - '0';
		if (sign == 1 && n > (INT_MAX - digit) / 10)
			return (0);
		if (sign == -1 && -n < (INT_MIN + digit) / 10)
			return (0);
		n = n * 10 + digit;
		str++;
	}
	*out = (int)(n * sign);
	return (1);
}
