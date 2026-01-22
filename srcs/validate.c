#include "helpers.h"
#include "push_swap.h"

int	repeated_nums(int *tab, int size)//should size be a size_t?
{
	size_t	i;
	size_t	j;

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

int	*normalize_input(int ac, char *av[], int *size)//split this in two functions plss
{
	char	*joined;
	char	**tokens;
	int	*tab;

	joined = ft_strjoin(ac - 1, av + 1, " \t\n\r\f\v");//change to take &ft_isspc?
	if (!joined)
		return (NULL);
	tokens = ft_split(joined);
	free(joined);//ok to keep ths here?
	if (!tokens)
		return (NULL);
	*size = count_tokens(tokens);
	tab = tokens_to_tab(tokens);
	if (!tab)
	{
		print_error();
		free_tokens(tokens);
		return (NULL);
	}
	print_tab(tab, *size);//REMOVE!!
	free_tokens(tokens);
	return (tab);
}

int	*tabdup(int *tab, int size)
{
	int	*dup;
	int	i;

	i = 0;
	dup = malloc(sizeof(int) * size);
	if (!dup)
	{
		return (NULL);
	}
	while (i < size)
	{
		dup[i] = tab[i];
		i++;
	}
	return (dup);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{

		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int	get_sorted_index(int *sorted, int size, int current)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (current == sorted[index])
			return (index);
		index++;
	}
	return (-1);
}
