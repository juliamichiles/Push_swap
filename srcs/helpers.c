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

int	*tokens_to_tab(char *tokens[])
{
	int	*tab;
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
		value = ft_atol(tokens[i]);
		if (value > INT_MAX || value < INT_MIN)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = value;
		i++;
	}
	return (tab);
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		return (1);
	while (i < size - 1)
	{
		if (tab[i + 1] <= tab[i])
			return (0);
		i++;
	}
	return (1);
}
/*
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
}*/
