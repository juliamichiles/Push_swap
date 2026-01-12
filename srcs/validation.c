#include "push_swap.h"

int	check_format(char *token)
{
	int	num_flag;

	num_flag = 0;
	if (!token)
		return (0);
	if (*token == '+' || *token == '-')
		token++;
	if (ft_isnum(*token))
		num_flag = 1;
	while (*token)
	{
		if (!ft_isnum(*token))
			return (0);
		token++;
	}
	if (!num_flag)
		return (0);
	return (1);

}

int	repeated_tokens(char *tokens[])
{
	int	i;
	int	j;

	i = 0;
	while (tokens[i])
	{
		j = i + 1;
		while (tokens[j] && tokens[i])
		{
			if (ft_strcmp(tokens[i], tokens[j]) != 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
