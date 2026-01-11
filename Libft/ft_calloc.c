/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:03:14 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/17 13:49:22 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*m_block;
	size_t			b_count;

	if (nmemb == 0 || size == 0)
		b_count = 1;
	else if (nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb && size)
		b_count = nmemb * size;
	m_block = malloc(b_count);
	if (!m_block)
		return (NULL);
	ft_bzero(m_block, b_count);
	return (m_block);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	unsigned char	*og_block;
	unsigned char	*ft_block;
	size_t	nmemb;
	size_t	size;
	size_t	t_size;
	size_t	i = 0;

	if (ac != 3)
	{
		printf("arguments should be: [nmemb][size]\n");
		return 1;
	}
	nmemb = (size_t)ft_atoi(av[1]);
	size = (size_t)ft_atoi(av[2]);
	t_size = nmemb * size;
	og_block = (unsigned char *)calloc(nmemb, size);
	ft_block = (unsigned char *)ft_calloc(nmemb, size);
	if (!og_block)
		printf("OG: [NULL]\n");
	if (!ft_block)
		printf("FT: [NULL]\n");
	if (og_block)
	{
		printf("OG:\n");
		while (i < t_size)
			printf("[%d]", og_block[i++]);
		printf("\n");
		free(og_block);
	}
	i = 0;
	if (ft_block)
	{
		printf("FT\n");
		while (i < t_size)
			printf("[%d]", ft_block[i++]);
		printf("\n");
		free(ft_block);
	}
	return (0);
}*/
