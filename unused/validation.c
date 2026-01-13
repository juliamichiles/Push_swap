#include "push_swap.h"

/*
int	check_format(char *token)
{
	if (!token || !(*token))
		return (0);
	if (*token == '+' || *token == '-')
		token++;
	if (!ft_isdigit(*token))
		return (0);
	while (*token)
	{
		if (!ft_isdigit(*token))
			return (0);
		token++;
	}
	return (1);
}*/

int	validate_tokens(char *tokens[])
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (!check_format(tokens[i]))
			return (print_error());
		i++;
	}
	if (!repeated_tokens(tokens))
		return (print_error());
	return 1;
}
