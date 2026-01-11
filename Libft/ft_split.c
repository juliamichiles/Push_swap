/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliatav <juliatav@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:43:56 by juliatav          #+#    #+#             */
/*   Updated: 2025/10/24 14:51:19 by juliatav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		start;

	count = 0;
	start = 0;
	while (*s)
	{
		if (!start && *s != c)
		{
			count++;
			start = 1;
		}
		if (start && *s == c)
			start = 0;
		s++;
	}
	return (count);
}

static char	*set_words(const char *s, char c)
{
	char	*word;
	size_t	len;

	len = wordlen(s, c) + 1;
	word = (char *)malloc(len);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len);
	return (word);
}

static void	free_words(char **split, size_t current)
{
	size_t	i;

	i = 0;
	while (i < current)
		free(split[i++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;

	i = 0;
	count = count_words(s, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	while (i < count)
	{
		while (*s == c && *s)
			s++;
		split[i] = set_words(s, c);
		if (!split[i])
		{
			free_words(split, i);
			return (NULL);
		}
		while (*s != c && *s)
			s++;
		i++;
	}
	split[i] = NULL;
	return (split);
}
/*
int	main(int ac, char **av)
{
	char	**split;
	int	i = 0;
	if (ac != 3)
		return 1;
	split = ft_split(av[1], av[2][0]);
	if (!split)
	{
		printf("[NULL]\n");
		return (1);
	}
	while (split[i])
		printf("[%s]\n", split[i]);
	if (!split[i])
		printf("[NULL]\n");
	free_words(split, i);
}*/
