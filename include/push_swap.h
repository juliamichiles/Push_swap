#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "libft.h"
#include "helpers.h"

typedef struct	s_stack
{
	int			value;
	int			index;
	int			pos;
	int			target;
	int			cost_a;
	int			cost_b;
	struct s_stack		*next;
}	t_stack;

#endif
