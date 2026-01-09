#include "push_swap.h"

int	ft_isspace(char c)//REMOVE ONCE LIBFT IS ON!!!
{
	if ((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}

int	ft_strnum(char *str)
{
/*	int	num_flag;

	num_flag = 0;*/
	if (!str || !(*str))
		return 0;
	if (*str == '+' || *str == '-' || ft_isspace(*str))//should accept '+'?
		str++;
	while (*str)
	{
		/*if (*str >= '0' && *str <= '9')//replace with ft_issnum
			num_flag = 1;*/
		if (!(*str >= '0' && *str <= '9') && !ft_isspace(*str))
			return 0;
		str++;
	}
	if (!num_flag)
		return 0;
	return 1;
}

int	is_valid(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strnum(av[i]))
		{
			print_error;
			return 0;
		}
		else
			write(1, "OK\n", 3);//remove me
		i++;
	}
	return 1;
}
