/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 18:48:37 by juliatav          #+#    #+#             */
/*   Updated: 2025/09/08 20:39:03 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_strs_len(char **strs, int size)
{
	int	lens;
	int	i;

	i = 0;
	lens = 0;
	while (i < size)
	{
		lens += ft_strlen(strs[i]);
		i++;
	}
	return (lens);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		total_size;
	int		i;

	i = 0;
	if (size == 0)
	{
		joined = malloc(1);
		*joined = '\0';
		return (joined);
	}
	total_size = (ft_strs_len(strs, size) + ((size - 1) * ft_strlen(sep)) + 1);
	joined = malloc(total_size * sizeof(char));
	if (!joined)
		return (NULL);
	*joined = '\0';
	while (i < size)
	{
		ft_strcat(joined, strs[i]);
		if (i < size - 1)
			ft_strcat(joined, sep);
		i++;
	}
	return (joined);
}
/*
int	main(int ac, char **av)
{
	char	*sep = "";
	char	*join;

	join = ft_strjoin(ac - 1, av + 1, sep);
	if (!join)
	{
		printf("MALLOC FAILED\n");
		return (1);
	}
	printf("%s\n", join);
	free(join);
}*/
