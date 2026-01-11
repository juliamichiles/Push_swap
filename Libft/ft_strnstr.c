/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:52:53 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/23 18:06:08 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;

	i = 0;
	little_len = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	while (big[i] && (i + little_len <= len))
	{
		if (!ft_strncmp(&big[i], little, (little_len)))
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <bsd/string.h>
int	main(int ac, char **av)
{
	char	*ft, *og;
	size_t	n;
	if (ac != 4)
	{
		printf("arguments should be: [big][little][n]\n");
		return 1;
	}
	n = (size_t)ft_atoi(av[3]);
	ft = ft_strnstr(av[1], av[2], n);
	og = strnstr(av[1], av[2], n);
	if (!ft)
		printf("FT: [NULL]\n");
	else
		printf("FT: [%s]\n", ft);
	if (!og)
		printf("OG: [NULL]\n");
	else
		printf("OG: [%s]\n", og);
	return (0);
}*/
