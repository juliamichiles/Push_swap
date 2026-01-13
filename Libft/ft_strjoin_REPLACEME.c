#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int     ft_find_size(int size, char *sp, char **st);
char	*ft_strjoin_REPLACEME(int size, char **strs, char *sep)
{
	char	*joined;
	int	total_size;
	int	i;
	int	j;
	int	n;
	int	k;

	i = 0;
	n = 0;
	total_size = ft_find_size(size, sep, strs);
	if (size == 0)
	{
		return(malloc(1));
	}
	joined = malloc(total_size + 1);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			joined[n] = strs[i][j];
			j++;
			n++;
		}
		k = 0;
		while ((sep[k] != '\0') && (i < size - 1))
		{
		 	joined[n] = sep[k];
			k++;
			n++;
		}
		i++;
	}
	joined[n] = '\0';
	return(joined);
}
int	ft_find_size(int size, char *sp, char **st)
{
	int	i;
	int	j;
	int	sum_size;

	i = 0;
	sum_size = 0;
	while (i < size)
	{
		j = 0;
		while (st[i][j] != '\0')
		{
			j++;
		}
		sum_size = sum_size + j;
		i++;
	}
	sum_size = sum_size + size;

	int	k;

	k = 0;
	while (sp[k] != '\0')
	{
		k++;
	}
	sum_size = sum_size + k + 1;
	return(sum_size);
}
/*
int	main(void)
{
	int	size = 4;
	char	*sep = "";
	char	*str[] = {"hello", "world", "foo", "bar", "baz"};
	char	*join;

	join = ft_strjoin(size, str, sep);
	printf("%s\n", join);
	free(join);
	return(0);
}*/
