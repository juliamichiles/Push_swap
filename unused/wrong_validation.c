#include "push_swap.h"
#include "helpers.h"

int	ft_isspace(char c)//add to libft?
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	invalid_chars(char *str)//checks for invalid chars or no digits in string
{
	int	num_flag;

	num_flag = 0;
	while (*str)
	{
		if (ft_isnum(*str))
			num_flag = 1;
		if (!(*str == '+' || *str == '-')
			&& !ft_isspace(*str) && !ft_isnum(*str))
			return (0);
		str++;
	}
	if (!num_flag)
		return (0);
	return (1);
}

int	check_format(char *str)
{
	if (!str || !(*str))
		return (0);
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		str++;
		if (!ft_isnum(*str))
			return (0);
	}
	else if ((!ft_isnum(*str))
		return (0);
	return (1);
}

int	is_valid(int ac, char *av[])//caller must pass split or av+1
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!check_format(av[i]) || !invalid_chars(av[i]))
		{
			print_error();
			return (0);
		}
		else
			write(1, "OK\n", 3);//remove me
		i++;
	}
	return (1);
}
