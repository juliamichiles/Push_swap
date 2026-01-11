/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:37:49 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/16 17:59:55 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_src = (const unsigned char *)src;
	p_dest = (unsigned char *)dest;
	if (p_dest == p_src || !n)
		return (dest);
	if (p_dest < p_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			--n;
			p_dest[n] = p_src[n];
		}
	}
	return (dest);
}
