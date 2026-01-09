#include "validation.h"
#include "push_swap.h"

int	main(int ac, char *av[])
{
	if (ac < 2)
		return (1);
	if (!is_valid(ac, av))
		return (1);
	//does everything else
	return (0);
}
