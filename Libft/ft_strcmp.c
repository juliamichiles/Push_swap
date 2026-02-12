/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:00:10 by juliatav          #+#    #+#             */
/*   Updated: 2026/02/12 16:00:11 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main(int ac, char **av)
{
	if(ac == 3)
	{
		printf("FT: %d\n", ft_strcmp(av[1], av[2]));
		printf("OG: %d\n", strcmp(av[1], av[2]));
	}
	return(0);
}*/
