#include "push_swap.c"


int	single_arg(char *str)
{
	char	**split;
	int	i;

	i = 0;
	split = ft_split(str, ' ');//only counts space as a separator
	if (!split)
		return (-1);
	while (split[i])
	{
		if(!is_valid(split[i]))
			return 0;

	}
}
