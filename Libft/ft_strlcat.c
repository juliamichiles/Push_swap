/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:22:17 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/23 15:22:20 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	while (src[i] && i < (size - d_len - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
int	main(int ac, char **av)
{
	char	og_dest[SIZE];
	char	ft_dest[SIZE];
	size_t	ft_ret, og_ret;

	if (ac != 2)
		return 1;
	ft_ret = ft_strlcat(ft_dest, av[1], (size_t)SIZE);
	og_ret = strlcat(og_dest, av[1], (size_t)SIZE);
	printf("FT: %s (%lu)\n", ft_dest, ft_ret);
	printf("OG: %s (%lu)\n", og_dest, og_ret);
}*/
