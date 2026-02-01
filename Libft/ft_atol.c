/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:08:25 by juliatav          #+#    #+#             */
/*   Updated: 2026/01/16 18:33:08 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atol(const char *nptr)
{
	long long	sign;
	long long	n;

	n = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + ((*nptr) - 48);
		nptr++;
	}
	return (n * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int ac, char **av)
{
	char	*s = "\t\n\v\f\r  -42xxx";
	int		i = 1;
	
	printf("OG: %s -> %d\n", s, atoi(s));
	printf("FT: %s -> %d\n", s, ft_atoi(s));
	while (i < ac)
	{
		printf("OG: %s -> %d\n", av[i], atoi(av[i]));
		printf("FT: %s -> %d\n", av[i], ft_atoi(av[i]));
		i++;
	}
}*/
