/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:23:00 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/23 18:06:28 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char const *set, char c)
{
	if (!c)
		return (0);
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	find_start(char const *set, char const *s1)
{
	int	start;

	start = 0;
	while (is_charset(set, *s1))
	{
		start++;
		s1++;
	}
	return (start);
}

static int	find_end(char const *set, char const *s1)
{
	size_t	len;
	int		end;

	end = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (0);
	while (is_charset(set, s1[len - 1]) && len > 0)
	{
		end++;
		len--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	if (!(*s1))
		return (ft_calloc(1, 1));
	if (!(*set))
		return (ft_strdup(s1));
	end = find_end(set, s1);
	start = find_start(set, s1);
	if (start + end >= ft_strlen(s1))
		return (ft_calloc(1, 1));
	len = ft_strlen(s1) - start - end;
	trimed = ft_calloc(len + 1, 1);
	if (!trimed)
		return (NULL);
	ft_memcpy(trimed, s1 + start, len);
	return (trimed);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*trimed;
	char	*s1 = "x";
	char	*set = "x";

	trimed = ft_strtrim(s1, set);
	if (!trimed)
		return 1;
	printf("%s\n", trimed);
	free(trimed);
}

int	main(int ac, char **av)
{
	char *trimed;

	if (ac != 3)
	{
		printf("arguments should be: [s1][set]\n");
		return 1;
	}
	trimed = ft_strtrim(av[1], av[2]);
	if (!trimed)
	{
		printf("[NULL]\n");
		return 1;
	}
	printf("%s\n", trimed);
	free(trimed);
}*/
