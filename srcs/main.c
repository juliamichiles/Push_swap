//#include "validation.h"
#include "helpers.h"
#include "push_swap.h"

#include <stdio.h> //REMOVE!!!
void	print_tab(int *tab, int size)
{
	int	 i = 0;

	while (i < size)
		printf("[%d]", tab[i++]);
	printf("\n");
}

int	main(int ac, char *av[])//split this in two functions plss
{
	char	*joined;
	char	**tokens;
	int	*tab;

	if (ac < 2)
		return (1);
	joined = ft_strjoin_REPLACEME(ac - 1, av + 1, " ");
	if (!joined)
		return (1);
	tokens = ft_split(joined, ' ');
	free(joined);//ok to keep ths here?
	if (!tokens)
		return 1;
	tab = tokens_to_tab(tokens);
	if (!tab)
	{
		print_error();
		free_tokens(tokens);
		return (1);
	}	
	print_tab(tab, count_tokens(tokens));
	free_tokens(tokens);
	free(tab);
	return (0);
}
