#include "validation.h"
#include "push_swap.h"


int	main(int ac, char *av[])
{
	char	**split;
	int	i;

	i = 0;
	if (ac < 2)
		return (1);
	if (ac == 2)
	{

	}
	if (!is_valid(ac -1, av+1))
		return (1);
	//does everything else
	return (0);
}
