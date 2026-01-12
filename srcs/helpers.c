#include "push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	free_tokens(char *tokens[])
{
	int	i;

	i = 0;
	while (tokens[i])
		free(tokens[i++]);
	free(tokens);
}

int	count_tokens(char *tokens[])
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	return (count);
}

int	*tokens_to_tab(char *tokens[])//convert directly to list instead?
{
	int	*tab;//change to stack
	int	count;
	int	i;

	i = 0;
	count = count_tokens(tokens);
	tab = malloc(count * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		tab[i] = ft_atoi(tokens[i]);
		i++;
	}
	return (tab);
}
