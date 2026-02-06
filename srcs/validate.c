#include "push_swap.h"

static int	repeated_nums(int *tab, int size)//should size be a size_t?
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_token(char *token)
{
	if (ft_strlen(token) > 1)
		if (*token == '+' || *token == '-')
			token++;
	while (*token)
	{
		if (!ft_isdigit(*token))
			return (0);
		token++;
	}
	return (1);
}

int	check_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!check_token(tokens[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*validate(int ac, char *av[], int *size)
{
	int	*tab;

	tab = normalize_input(ac, av, size);
	if (!tab)
		return (NULL);
	if (!repeated_nums(tab, *size))
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
