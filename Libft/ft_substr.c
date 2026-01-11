/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:41:12 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/23 17:39:35 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	sub_len = s_len - start;
	if (len > sub_len)
		len = sub_len;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	unsigned int	len;
	char			*sub;
	size_t			start;

	if (ac != 4)
	{
		printf("arguments should be: [string][start][len]\n");
		return 1;
	}
	start = (size_t)ft_atoi(av[2]);
	len = (unsigned int)ft_atoi(av[3]);
	sub = ft_substr(av[1], start, len);
	//sub = ft_substr(NULL, start, len);
	if (!sub)
	{
		printf("[NULL]\n");
		return 1;
	}
	printf("sub: %s\n", sub);
	free(sub);
	return 0;
}*/
