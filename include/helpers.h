#ifndef HELPERS_H
# define HELPERS_H

void	print_error(void);
int	count_tokens(char *tokens[]);
int	*tokens_to_tab(char *tokens[]);
int	safe_atoi(const char *str, int *out);

void	free_tokens(char *tokens[]);
#endif
