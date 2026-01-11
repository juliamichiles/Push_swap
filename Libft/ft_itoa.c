/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:30:01 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/23 15:30:04 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char	*set_num(char *num, int n, int size)
{
	int	negative;

	size -= 1;
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	while (n > 9)
	{
		num[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	num[size] = (n % 10) + '0';
	if (negative)
		num[--size] = '-';
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		size;

	size = find_size(n);
	if (n == INT_MIN)
	{
		num = ft_strdup("-2147483648");
		if (!num)
			return (NULL);
		return (num);
	}
	num = ft_calloc(size + 1, sizeof(char));
	if (!num)
		return (NULL);
	num = set_num(num, n, size);
	return (num);
}
